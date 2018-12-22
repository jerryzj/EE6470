#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

#include "OpUtil.h"
#include "Config.h"

// prints all channels
void printTensor(const ShapeTy shape, const DataTy* data_ptr) {
  std::cout << std::setprecision(precision);
  std::cout << std::fixed;
  for(uint n=0; n<shape.n; ++n) {
          std::cout << "{\n";
  for(uint c=0; c<shape.c; ++c) {
          std::cout << "\t[\n";
  for(uint h=0; h<shape.h; ++h) {
          std::cout << "\t";
  for(uint w=0; w<shape.w; ++w) {
          const auto offset = shape.Idx(n, c, h, w);
          const auto data = data_ptr[offset];
          std::cout << std::setw(precision) << data << " ";
  }
          std::cout << '\n';
  }
          std::cout << "\t]\n";
  }
          std::cout << "}\n";
  }
}

// channel is used to specify the channel to print on screen.
void printTensor(const ShapeTy shape, const DataTy* data_ptr,
                 const unsigned int channel) {
  const unsigned int zero = 0;
  const auto small_shape = ShapeTy(shape.n, 1, shape.h, shape.w);
  const auto offset = shape.Idx(zero, channel, zero, zero);
  auto* small_data_ptr = &(data_ptr[offset]);
  printTensor(small_shape, small_data_ptr);
}

unsigned int implyStride(unsigned int in_shape_h, unsigned int out_shape_h) {
  const float in_h = static_cast<float>(in_shape_h);
  const float out_h = static_cast<float>(out_shape_h);
  const float ratio = in_h / out_h;
  const unsigned int stride = static_cast<unsigned int>(round(ratio));
  return stride;
}

// Compensate the offset to the point, useful for the case
// of that we may want get a continuous subimage
DataTy* getPtr(void* raw_ptr, const uint32_t offset) {
  auto* data = static_cast<DataTy*>(raw_ptr);
  const auto data_offset = offset / sizeof(DataTy);
  auto* data_ptr = &(data[data_offset]);
  assert(data);
  assert(data_ptr);
  return data_ptr;
}


