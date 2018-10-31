#include <cmath>
#include "runtime.h"
using namespace std;
extern "C" void fuse_conv2d_relu_2( void* args,  void* arg_type_ids, int num_args) {
  void* stack_tcode = malloc(sizeof(int) * 4);;
  void* stack_value = malloc(sizeof(TVMValue) * 4);;
  void* stack_array = malloc(sizeof(DLTensor) * 3);;
  void* stack_shape = malloc(sizeof(long) * 20);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* input1 = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  float* input2 = (float*)(((TVMArray*)arg2)[0].data);
  long* arg2_shape = (long*)(((TVMArray*)arg2)[0].shape);
  long* arg2_strides = (long*)(((TVMArray*)arg2)[0].strides);
  if (!(arg2_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 1) * 14) * 14)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i2 = 0; i2 < 14; ++i2) {
    for (int i3 = 0; i3 < 14; ++i3) {
      (( float*)pad_temp)[((i2 * 14) + i3)] = input0[((i2 * 14) + i3)];
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 4) * 12) * 12)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)1;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)4;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)3;
  (( long*)stack_shape)[9] = (long)3;
  (( long*)stack_shape)[10] = (long)9;
  (( long*)stack_shape)[11] = (long)9;
  (( long*)stack_shape)[12] = (long)3;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (( long*)stack_shape)[14] = (long)4;
  (( long*)stack_shape)[15] = (long)12;
  (( long*)stack_shape)[16] = (long)12;
  (( long*)stack_shape)[17] = (long)144;
  (( long*)stack_shape)[18] = (long)12;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[2].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[2].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[2].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[2].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (( int*)stack_tcode)[2] = 7;
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* compute1 = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)(((4 * 4) * 1) * 1)), 2, 32);
  if (compute1 == NULL) {
    (void)assert(0);
  }
  for (int i0 = 0; i0 < 4; ++i0) {
    (( float*)compute1)[i0] = input2[i0];
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 4) * 12) * 12)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  for (int ax1 = 0; ax1 < 4; ++ax1) {
    for (int ax2 = 0; ax2 < 12; ++ax2) {
      for (int ax3 = 0; ax3 < 12; ++ax3) {
        (( float*)tensor)[((((ax1 * 12) + ax2) * 12) + ax3)] = ((( float*)compute)[((((ax1 * 12) + ax2) * 12) + ax3)] + (( float*)compute1)[ax1]);
      }
    }
  }
  (( long*)stack_shape)[0] = (long)4;
  (( long*)stack_shape)[1] = (long)12;
  (( long*)stack_shape)[2] = (long)12;
  (( long*)stack_shape)[3] = (long)144;
  (( long*)stack_shape)[4] = (long)12;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)4;
  (( long*)stack_shape)[7] = (long)12;
  (( long*)stack_shape)[8] = (long)12;
  (( long*)stack_shape)[9] = (long)144;
  (( long*)stack_shape)[10] = (long)12;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute1) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_max_pool2d_2( void* args,  void* arg_type_ids, int num_args) {
  void* stack_tcode = malloc(sizeof(int) * 3);;
  void* stack_value = malloc(sizeof(TVMValue) * 3);;
  void* stack_array = malloc(sizeof(DLTensor) * 2);;
  void* stack_shape = malloc(sizeof(long) * 12);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* tensor = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  (( long*)stack_shape)[0] = (long)4;
  (( long*)stack_shape)[1] = (long)12;
  (( long*)stack_shape)[2] = (long)12;
  (( long*)stack_shape)[3] = (long)144;
  (( long*)stack_shape)[4] = (long)12;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = input0;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)4;
  (( long*)stack_shape)[7] = (long)6;
  (( long*)stack_shape)[8] = (long)6;
  (( long*)stack_shape)[9] = (long)36;
  (( long*)stack_shape)[10] = (long)6;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = tensor;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (void)TVMFuncCall(pool2d,((TVMValue*)stack_value)[0],2-0);
}

extern "C" void fuse_conv2d_relu_3( void* args,  void* arg_type_ids, int num_args) {
  void* stack_tcode = malloc(sizeof(int) * 4);;
  void* stack_value = malloc(sizeof(TVMValue) * 4);;
  void* stack_array = malloc(sizeof(DLTensor) * 3);;
  void* stack_shape = malloc(sizeof(long) * 20);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* input1 = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  float* input2 = (float*)(((TVMArray*)arg2)[0].data);
  long* arg2_shape = (long*)(((TVMArray*)arg2)[0].shape);
  long* arg2_strides = (long*)(((TVMArray*)arg2)[0].strides);
  if (!(arg2_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 4) * 6) * 6)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 4; ++i1) {
    for (int i2 = 0; i2 < 6; ++i2) {
      for (int i3 = 0; i3 < 6; ++i3) {
        (( float*)pad_temp)[((((i1 * 6) + i2) * 6) + i3)] = input0[((((i1 * 6) + i2) * 6) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 4) * 4)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)4;
  (( long*)stack_shape)[1] = (long)6;
  (( long*)stack_shape)[2] = (long)6;
  (( long*)stack_shape)[3] = (long)36;
  (( long*)stack_shape)[4] = (long)6;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)4;
  (( long*)stack_shape)[8] = (long)3;
  (( long*)stack_shape)[9] = (long)3;
  (( long*)stack_shape)[10] = (long)36;
  (( long*)stack_shape)[11] = (long)9;
  (( long*)stack_shape)[12] = (long)3;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (( long*)stack_shape)[14] = (long)8;
  (( long*)stack_shape)[15] = (long)4;
  (( long*)stack_shape)[16] = (long)4;
  (( long*)stack_shape)[17] = (long)16;
  (( long*)stack_shape)[18] = (long)4;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[2].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[2].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[2].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[2].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (( int*)stack_tcode)[2] = 7;
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* compute1 = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)(((4 * 8) * 1) * 1)), 2, 32);
  if (compute1 == NULL) {
    (void)assert(0);
  }
  for (int i0 = 0; i0 < 8; ++i0) {
    (( float*)compute1)[i0] = input2[i0];
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 4) * 4)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  for (int ax1 = 0; ax1 < 8; ++ax1) {
    for (int ax2 = 0; ax2 < 4; ++ax2) {
      for (int ax3 = 0; ax3 < 4; ++ax3) {
        (( float*)tensor)[((((ax1 * 4) + ax2) * 4) + ax3)] = ((( float*)compute)[((((ax1 * 4) + ax2) * 4) + ax3)] + (( float*)compute1)[ax1]);
      }
    }
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)4;
  (( long*)stack_shape)[2] = (long)4;
  (( long*)stack_shape)[3] = (long)16;
  (( long*)stack_shape)[4] = (long)4;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)4;
  (( long*)stack_shape)[8] = (long)4;
  (( long*)stack_shape)[9] = (long)16;
  (( long*)stack_shape)[10] = (long)4;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute1) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_max_pool2d_3( void* args,  void* arg_type_ids, int num_args) {
  void* stack_tcode = malloc(sizeof(int) * 3);;
  void* stack_value = malloc(sizeof(TVMValue) * 3);;
  void* stack_array = malloc(sizeof(DLTensor) * 2);;
  void* stack_shape = malloc(sizeof(long) * 12);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* tensor = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)4;
  (( long*)stack_shape)[2] = (long)4;
  (( long*)stack_shape)[3] = (long)16;
  (( long*)stack_shape)[4] = (long)4;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = input0;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[0].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[0].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[0].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[0].ctx.device_type) = 13;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)2;
  (( long*)stack_shape)[8] = (long)2;
  (( long*)stack_shape)[9] = (long)4;
  (( long*)stack_shape)[10] = (long)2;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = tensor;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].dtype.code) = (unsigned char)2;
  (((TVMArray*)stack_array)[1].dtype.bits) = (unsigned char)32;
  (((TVMArray*)stack_array)[1].dtype.lanes) = (unsigned short)1;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMArray*)stack_array)[1].ctx.device_id) = dev_id;
  (((TVMArray*)stack_array)[1].ctx.device_type) = 13;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (( int*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (( int*)stack_tcode)[1] = 7;
  (void)TVMFuncCall(pool2d,((TVMValue*)stack_value)[0],2-0);
}

extern "C" void fuse_reshape_flatten_1( void* args,  void* arg_type_ids, int num_args) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* tensor = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  for (int ax1 = 0; ax1 < 32; ++ax1) {
    tensor[ax1] = input0[(((ax1 / 4) * 4) + ((((ax1 / 2) % 2) * 2) + (ax1 % 2)))];
  }
}

extern "C" void fuse_dense_1( void* args,  void* arg_type_ids, int num_args) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_type = (((TVMArray*)arg0)[0].ctx.device_type);
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* input1 = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  float* input2 = (float*)(((TVMArray*)arg2)[0].data);
  long* arg2_shape = (long*)(((TVMArray*)arg2)[0].shape);
  long* arg2_strides = (long*)(((TVMArray*)arg2)[0].strides);
  if (!(arg2_strides == NULL)) {
  }
  float* compute = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  void* compute1 = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((4 * 1) * 10)), 2, 32);
  if (compute1 == NULL) {
    (void)assert(0);
  }
  for (int j = 0; j < 10; ++j) {
    (( float*)compute1)[j] = 0.000000e+00f;
    for (int k = 0; k < 32; ++k) {
      (( float*)compute1)[j] = ((( float*)compute1)[j] + (input0[k] * input1[((j * 32) + k)]));
    }
  }
  for (int j1 = 0; j1 < 10; ++j1) {
    compute[j1] = ((( float*)compute1)[j1] + input2[j1]);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute1) != 0) {
    (void)assert(0);
  }
}

