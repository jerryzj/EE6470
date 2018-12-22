#include <cmath>
#include <cfloat>
#include <cassert>
#include <iostream>

#include "Op.h"
#include "OpUtil.h"
#include "ShapeTy.h"
#include "Config.h"
#include "sync.h"

extern PoolConfig pool_config;
extern float input_f[4 * 12 * 12];
extern float output_f[4 * 6 * 6];
extern int core_num;

void conv2d(TVMValue stack_value, int arg_num) {
  assert(arg_num == 3);
  // input data
  auto* stack_array = static_cast<TVMArray*>(stack_value.v_handle);
  auto* data_ptr = getPtr(stack_array[0].data,
                          stack_array[0].byte_offset);
  const ShapeTy data_shape = ShapeTy(stack_array[0].shape,
                                     stack_array[0].ndim);

  // conv kernel
  auto* kernel_ptr = getPtr(stack_array[1].data,
                          stack_array[1].byte_offset);
  const ShapeTy kernel_shape = ShapeTy(stack_array[1].shape,
                                       stack_array[1].ndim);

  // output feature
  auto* output_ptr = getPtr(stack_array[2].data,
                          stack_array[2].byte_offset);
  const ShapeTy output_shape = ShapeTy(stack_array[2].shape,
                                       stack_array[2].ndim);

  // This stride means the input/output ratio
  const unsigned int stride = implyStride(data_shape.h - kernel_shape.h,
                                          output_shape.h);

  if (print_shape) {
    // prints the shape of data
    std::cout << "Conv:\n";
    std::cout << "\t";
    std::cout << "data size: " <<  data_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "kernel size: "<<  kernel_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "output size: " <<  output_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "stride: " << stride << "\n";
  }

  assert(data_ptr);
  assert(kernel_ptr);
  assert(output_ptr);

  assert(data_shape.size());
  assert(kernel_shape.size());
  assert(output_shape.size());

  assert(output_shape.c == kernel_shape.n);
  assert(data_shape.c == kernel_shape.c);

  // Real compuatations
  for (unsigned int c=0; c<output_shape.c; ++c) {
  for (unsigned int h=0; h<output_shape.h; ++h) {
  for (unsigned int w=0; w<output_shape.w; ++w) {
    const auto Oidx = output_shape.Idx(c, h, w);
    output_ptr[Oidx] = 0; 
    for (unsigned int rc=0; rc<kernel_shape.c; ++rc) {
    for (unsigned int rh=0; rh<kernel_shape.h; ++rh) {
    for (unsigned int rw=0; rw<kernel_shape.w; ++rw) {
      const auto Ih = (stride * h + rh);
      const auto Iw = (stride * w + rw);
      const auto Iidx = data_shape.Idx(rc, Ih, Iw);
      // This stride means the memory displacement of each channel/height index
      const auto Kidx = kernel_shape.Idx(c, rc, rh, rw);
      output_ptr[Oidx] += (data_ptr[Iidx] * kernel_ptr[Kidx]);
    }}}
  }}}
  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }

}

void pool2d(TVMValue stack_value, int arg_num) {
  assert(arg_num == 2);
  // input data
  auto* stack_array = static_cast<TVMArray*>(stack_value.v_handle);
  auto* data_ptr = getPtr(stack_array[0].data,
                          stack_array[0].byte_offset);
  const ShapeTy data_shape = ShapeTy(stack_array[0].shape,
                                     stack_array[0].ndim);

  // output feature
  auto* output_ptr = getPtr(stack_array[1].data,
                          stack_array[1].byte_offset);
  const ShapeTy output_shape = ShapeTy(stack_array[1].shape,
                                     stack_array[1].ndim);

  assert(data_ptr);
  assert(output_ptr);
  assert(data_shape.c == output_shape.c);
  assert(data_shape.h >= output_shape.h);
  assert(data_shape.w >= output_shape.w);

  const unsigned int stride = implyStride(data_shape.h, output_shape.h);
  assert(stride > 1);
  if (print_shape) {
    // prints the shape of data
    std::cout << "Pool:\n";
    std::cout << "\t";
    std::cout << "data size: " <<  data_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "output size: " <<  output_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "stride: " << stride << "\n";
  }
  // Copy configuration information
  pool_config.in_w   = data_shape.w;
  pool_config.in_h   = data_shape.h;
  pool_config.in_ch  = data_shape.c;
  pool_config.stride = stride;
  pool_config.out_w  = output_shape.w;
  pool_config.out_h  = output_shape.h;
  pool_config.out_ch = output_shape.c;
  // Copy Input feature map
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto Iidx = data_shape.Idx(c,h,w);
    input_f[Iidx] = data_ptr[Iidx];
  }}}
  barrier(core_num);
  // Real compuatations, divide computation by channel
  int ch_start = (pool_config.out_ch / core_num) * gethartid();
  int ch_end   = (pool_config.out_ch / core_num) * (gethartid()+ 1);
  for(unsigned int c = ch_start; c < ch_end; ++c) {
  for(unsigned int h = 0; h < pool_config.out_h; ++h) {
  for(unsigned int w = 0; w < pool_config.out_w; ++w) {
    const auto Oidx = c * pool_config.out_h * pool_config.out_w
                    + h * pool_config.out_w
                    + w;
    // initialize with minimum value
    auto max = -FLT_MAX;
    for(unsigned int fh = 0; fh < pool_config.stride; ++fh) {
    for(unsigned int fw = 0; fw < pool_config.stride; ++fw) {
      const auto Ih = (h * pool_config.stride) + fh;
      const auto Iw = (w * pool_config.stride) + fw;
      const auto Iidx = c * pool_config.in_h * pool_config.in_w
                      + h * pool_config.in_w
                      + w;
      max = fmax(max, input_f[Iidx]);
    }}
    output_f[Oidx] = max;
  }}}
  barrier(core_num);  // ensure compution in each core is done
  // Copy data back to output_ptr
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto Oidx = output_shape.Idx(c,h,w);
    output_ptr[Oidx] = output_f[Oidx];
  }}}
  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }

}

// proforms AX+B, where A is the input
void norm2d(TVMValue stack_value, int arg_num) {
  assert(arg_num == 4);
  // input data
  auto* stack_array = static_cast<TVMArray*>(stack_value.v_handle);
  auto* data_ptr = getPtr(stack_array[0].data,
                          stack_array[0].byte_offset);
  const ShapeTy data_shape = ShapeTy(stack_array[0].shape,
                                     stack_array[0].ndim);

  // A feature
  auto* A_ptr = getPtr(stack_array[1].data,
                          stack_array[1].byte_offset);
  const ShapeTy A_shape = ShapeTy(stack_array[1].shape,
                                     stack_array[1].ndim);

  // A feature
  auto* B_ptr = getPtr(stack_array[2].data,
                          stack_array[2].byte_offset);
  const ShapeTy B_shape = ShapeTy(stack_array[2].shape,
                                     stack_array[2].ndim);

  // output feature
  auto* output_ptr = getPtr(stack_array[3].data,
                          stack_array[3].byte_offset);
  const ShapeTy output_shape = ShapeTy(stack_array[3].shape,
                                     stack_array[3].ndim);

  assert(data_ptr);
  assert(A_ptr);
  assert(B_ptr);
  assert(output_ptr);
  assert(data_shape == output_shape);
  assert(A_shape.c == data_shape.c);
  assert(A_shape.w == 1);
  assert(A_shape.h == 1);
  assert(B_shape == A_shape);

  if (print_shape) {
    // prints the shape of data
    std::cout << "Norm:\n";
    std::cout << "\t";
    std::cout << "data size: " <<  data_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "A size: " <<  A_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "B size: " <<  B_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "output size: " <<  output_shape.to_str() << "\n";
  }

  // Real compuatations
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto idx = output_shape.Idx(c, h, w);
    output_ptr[idx] = (A_ptr[c] * data_ptr[idx]) + B_ptr[c];
  }}}

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }
}

void relu2d(TVMValue stack_value, int arg_num) {
  assert(arg_num == 2);
  // input data
  auto* stack_array = static_cast<TVMArray*>(stack_value.v_handle);
  auto* data_ptr = getPtr(stack_array[0].data,
                          stack_array[0].byte_offset);
  const ShapeTy data_shape = ShapeTy(stack_array[0].shape,
                                     stack_array[0].ndim);

  // output feature
  auto* output_ptr = getPtr(stack_array[1].data,
                          stack_array[1].byte_offset);
  const ShapeTy output_shape = ShapeTy(stack_array[1].shape,
                                     stack_array[1].ndim);

  assert(data_ptr);
  assert(output_ptr);
  assert(data_shape == output_shape);

  if (print_shape) {
    // prints the shape of data
    std::cout << "Relu:\n";
    std::cout << "\t";
    std::cout << "data size: " <<  data_shape.to_str() << "\n";
    std::cout << "\t";
    std::cout << "output size: " <<  output_shape.to_str() << "\n";
  }

  // Real compuatations
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto idx = output_shape.Idx(c, h, w);
    output_ptr[idx] = fmax(0, data_ptr[idx]);
  }}}

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }
}
