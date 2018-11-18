#include <cmath>
#include <cfloat>
#include <cassert>
#include <iostream>

#include "testbench/testbench.h"
#include "acc_platform/acc_platform.h"
#include "Op.h"
#include "OpUtil.h"
#include "ShapeTy.h"
#include "Config.h"

extern Testbench testbench;

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

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
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
  ConvConfig conv_config;
  conv_config.data_cube_in_width    = data_shape.w;
  conv_config.data_cube_in_height   = data_shape.h;
  conv_config.data_cube_in_channel  = data_shape.c;
  conv_config.filter_width          = kernel_shape.w;
  conv_config.filter_stride         = stride;
  conv_config.zero_padding          = 0;
  conv_config.data_cube_out_width  = ((conv_config.data_cube_in_height + 2 * conv_config.zero_padding)
                                   - conv_config.filter_width) / conv_config.filter_stride + 1;
  conv_config.data_cube_out_height  = conv_config.data_cube_out_width;
  conv_config.data_cube_out_channel = output_shape.c;
  conv_config.data_in_address       = POOL_BUFFER_ADDRESS;
  conv_config.kernel_addr       = POOL_BUFFER_ADDRESS
                                + (conv_config.data_cube_in_channel
                                * conv_config.data_cube_in_height
                                * conv_config.data_cube_in_width
                                ) * sizeof(float);
                    
  conv_config.data_out_address  = POOL_BUFFER_ADDRESS
                                + ((conv_config.data_cube_in_channel
                                * conv_config.data_cube_in_height
                                * conv_config.data_cube_in_width)
                                + (conv_config.filter_width 
                                * conv_config.filter_width
                                * conv_config.data_cube_in_channel
                                * conv_config.data_cube_out_channel
                                )) * sizeof(float);

  uint test_data_num(conv_config.data_cube_in_channel
                     * conv_config.data_cube_in_height
                     * conv_config.data_cube_in_width);

  uint result_num(conv_config.data_cube_out_channel
                  * conv_config.data_cube_out_height
                  * conv_config.data_cube_out_width);

  testbench.LoadTestData(GLOBAL_BUFFER_ADDRESS, data_ptr, test_data_num);

  vector<DmaChConfig> dma_config(1);
  dma_config[0].channel_enable  = 1;
  dma_config[0].source_address  = GLOBAL_BUFFER_ADDRESS;
  dma_config[0].dest_address    = conv_config.data_in_address;
  dma_config[0].transfer_length = test_data_num * sizeof(float);
  dma_config[0].transfer_type   = 3;
  dma_config[0].line_length     = 0;
  dma_config[0].line_stride     = 0;
  testbench.ConfigConvDMA(dma_config);

  uint test_kernel_num(conv_config.data_cube_in_channel
                     * conv_config.filter_width
                     * conv_config.filter_width
                     * conv_config.data_cube_out_channel);

  testbench.LoadTestData(GLOBAL_BUFFER_ADDRESS, kernel_ptr, test_kernel_num);

  dma_config[0].channel_enable  = 1;
  dma_config[0].source_address  = GLOBAL_BUFFER_ADDRESS;
  dma_config[0].dest_address    = conv_config.kernel_addr;
  dma_config[0].transfer_length = test_kernel_num * sizeof(float);
  dma_config[0].transfer_type   = 3;
  dma_config[0].line_length     = 0;
  dma_config[0].line_stride     = 0;
  testbench.ConfigConvDMA(dma_config);

  testbench.ConfigConvEngine(conv_config);

  /* Configure DMA to move results from buffer into RAM */
  dma_config[0].channel_enable  = 1;
  dma_config[0].source_address  = conv_config.data_out_address;
  dma_config[0].dest_address    = GLOBAL_BUFFER_ADDRESS;
  dma_config[0].transfer_length = result_num * sizeof(float);
  dma_config[0].transfer_type   = 3;
  dma_config[0].line_length     = 0;
  dma_config[0].line_stride     = 0;
  testbench.ConfigConvDMA(dma_config);

  /* Get result from RAM through debug transport (no timing effort) */
  testbench.GetResult(GLOBAL_BUFFER_ADDRESS, output_ptr, result_num);

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

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }

  // Real compuatations
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto Oidx = output_shape.Idx(c,h,w);
    // initialize with minimum value
    auto max = -FLT_MAX;
    for(unsigned int fh = 0; fh < stride; ++fh) {
    for(unsigned int fw = 0; fw < stride; ++fw) {
      const auto Ih = (h * stride) + fh;
      const auto Iw = (w * stride) + fw;
      const auto Iidx = data_shape.Idx(c, Ih, Iw);
      max = std::fmax(max, data_ptr[Iidx]);
    }}
    output_ptr[Oidx] = max;
  }}}
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

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }

  // Real compuatations
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto idx = output_shape.Idx(c, h, w);
    output_ptr[idx] = (A_ptr[c] * data_ptr[idx]) + B_ptr[c];
  }}}
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

  if (print_data) {
    // In this example, only prints the first channel
    std::cout << "Input: " << "\n";
    printTensor(data_shape, data_ptr, 0);
    std::cout << "Output: " << "\n";
    printTensor(output_shape, output_ptr, 0);
  }

  // Real compuatations
  for(unsigned int c = 0; c < output_shape.c; ++c) {
  for(unsigned int h = 0; h < output_shape.h; ++h) {
  for(unsigned int w = 0; w < output_shape.w; ++w) {
    const auto idx = output_shape.Idx(c, h, w);
    output_ptr[idx] = std::fmax(0, data_ptr[idx]);
  }}}
}
