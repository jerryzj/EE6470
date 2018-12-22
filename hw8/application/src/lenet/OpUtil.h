#pragma once

#include "ShapeTy.h"
#include "Config.h"
// prints all channels
void printTensor(const ShapeTy shape, const DataTy* data_ptr);
void printTensor(const ShapeTy shape, const DataTy* data_ptr,
                 const unsigned int channel);
unsigned int implyStride(unsigned int in_shape_h, unsigned int out_shape_h);
DataTy* getPtr(void* raw_ptr, const uint32_t offset);
