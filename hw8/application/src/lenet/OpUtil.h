#pragma once

#include "ShapeTy.h"
#include "Config.h"
// prints all channels
void printTensor(const ShapeTy shape, const DataTy* data_ptr);
void printTensor(const ShapeTy shape, const DataTy* data_ptr,
                 const unsigned int channel);
unsigned int implyStride(unsigned int in_shape_h, unsigned int out_shape_h);
DataTy* getPtr(void* raw_ptr, const uint32_t offset);


struct PoolConfig{
    int in_ch;
    int in_h;
    int in_w;
    int out_ch;
    int out_h;
    int out_w;
    int stride;
    PoolConfig(){
        in_ch = 0;
        in_h = 0;
        in_w = 0;
        out_ch = 0;
        out_h = 0;
        out_w = 0;
        stride = 0;
    }
};