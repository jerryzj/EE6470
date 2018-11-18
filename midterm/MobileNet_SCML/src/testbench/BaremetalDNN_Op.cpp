#include <cmath>
#include "runtime.h"
using namespace std;
extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_19( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 3) * 225) * 225)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 3; ++i1) {
    for (int i2 = 0; i2 < 225; ++i2) {
      for (int i3 = 0; i3 < 225; ++i3) {
        (( float*)pad_temp)[((((i1 * 225) + i2) * 225) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 224) + i2) * 224) + i3) + -225)]);
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 112) * 112)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)3;
  (( long*)stack_shape)[1] = (long)225;
  (( long*)stack_shape)[2] = (long)225;
  (( long*)stack_shape)[3] = (long)50625;
  (( long*)stack_shape)[4] = (long)225;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)3;
  (( long*)stack_shape)[8] = (long)3;
  (( long*)stack_shape)[9] = (long)3;
  (( long*)stack_shape)[10] = (long)27;
  (( long*)stack_shape)[11] = (long)9;
  (( long*)stack_shape)[12] = (long)3;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)8;
  (( long*)stack_shape)[15] = (long)112;
  (( long*)stack_shape)[16] = (long)112;
  (( long*)stack_shape)[17] = (long)12544;
  (( long*)stack_shape)[18] = (long)112;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 112) * 112)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)8;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)8;
  (( long*)stack_shape)[19] = (long)112;
  (( long*)stack_shape)[20] = (long)112;
  (( long*)stack_shape)[21] = (long)12544;
  (( long*)stack_shape)[22] = (long)112;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)112;
  (( long*)stack_shape)[8] = (long)112;
  (( long*)stack_shape)[9] = (long)12544;
  (( long*)stack_shape)[10] = (long)112;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_20( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 114) * 114)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 8; ++i1) {
    for (int i2 = 0; i2 < 114; ++i2) {
      for (int i3 = 0; i3 < 114; ++i3) {
        (( float*)PaddedInput)[((((i1 * 114) + i2) * 114) + i3)] = (((((1 <= i2) && (i2 < 113)) && (1 <= i3)) && (i3 < 113)) ? input0[(((((i1 * 112) + i2) * 112) + i3) + -113)] : 0.000000e+00f);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 112) * 112)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 8; ++c) {
    (( long*)stack_shape)[0] = (long)114;
    (( long*)stack_shape)[1] = (long)114;
    (( long*)stack_shape)[2] = (long)114;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 12996) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)112;
    (( long*)stack_shape)[9] = (long)112;
    (( long*)stack_shape)[10] = (long)112;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 12544) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 112) * 112)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)8;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)8;
  (( long*)stack_shape)[19] = (long)112;
  (( long*)stack_shape)[20] = (long)112;
  (( long*)stack_shape)[21] = (long)12544;
  (( long*)stack_shape)[22] = (long)112;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)112;
  (( long*)stack_shape)[8] = (long)112;
  (( long*)stack_shape)[9] = (long)12544;
  (( long*)stack_shape)[10] = (long)112;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_21( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 112) * 112)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 8; ++i1) {
    for (int i2 = 0; i2 < 112; ++i2) {
      for (int i3 = 0; i3 < 112; ++i3) {
        (( float*)pad_temp)[((((i1 * 112) + i2) * 112) + i3)] = input0[((((i1 * 112) + i2) * 112) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 112) * 112)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)16;
  (( long*)stack_shape)[7] = (long)8;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)8;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)16;
  (( long*)stack_shape)[15] = (long)112;
  (( long*)stack_shape)[16] = (long)112;
  (( long*)stack_shape)[17] = (long)12544;
  (( long*)stack_shape)[18] = (long)112;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 112) * 112)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)16;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)16;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)16;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)16;
  (( long*)stack_shape)[19] = (long)112;
  (( long*)stack_shape)[20] = (long)112;
  (( long*)stack_shape)[21] = (long)12544;
  (( long*)stack_shape)[22] = (long)112;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)16;
  (( long*)stack_shape)[1] = (long)112;
  (( long*)stack_shape)[2] = (long)112;
  (( long*)stack_shape)[3] = (long)12544;
  (( long*)stack_shape)[4] = (long)112;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)16;
  (( long*)stack_shape)[7] = (long)112;
  (( long*)stack_shape)[8] = (long)112;
  (( long*)stack_shape)[9] = (long)12544;
  (( long*)stack_shape)[10] = (long)112;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_22( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 113) * 113)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 16; ++i1) {
    for (int i2 = 0; i2 < 113; ++i2) {
      for (int i3 = 0; i3 < 113; ++i3) {
        (( float*)PaddedInput)[((((i1 * 113) + i2) * 113) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 112) + i2) * 112) + i3) + -113)]);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 56) * 56)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 16; ++c) {
    (( long*)stack_shape)[0] = (long)113;
    (( long*)stack_shape)[1] = (long)113;
    (( long*)stack_shape)[2] = (long)113;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 12769) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)56;
    (( long*)stack_shape)[9] = (long)56;
    (( long*)stack_shape)[10] = (long)56;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 3136) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 56) * 56)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)16;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)16;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)16;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)16;
  (( long*)stack_shape)[19] = (long)56;
  (( long*)stack_shape)[20] = (long)56;
  (( long*)stack_shape)[21] = (long)3136;
  (( long*)stack_shape)[22] = (long)56;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)16;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)16;
  (( long*)stack_shape)[7] = (long)56;
  (( long*)stack_shape)[8] = (long)56;
  (( long*)stack_shape)[9] = (long)3136;
  (( long*)stack_shape)[10] = (long)56;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_23( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 16) * 56) * 56)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 16; ++i1) {
    for (int i2 = 0; i2 < 56; ++i2) {
      for (int i3 = 0; i3 < 56; ++i3) {
        (( float*)pad_temp)[((((i1 * 56) + i2) * 56) + i3)] = input0[((((i1 * 56) + i2) * 56) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)16;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)16;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)16;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)32;
  (( long*)stack_shape)[15] = (long)56;
  (( long*)stack_shape)[16] = (long)56;
  (( long*)stack_shape)[17] = (long)3136;
  (( long*)stack_shape)[18] = (long)56;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)32;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)32;
  (( long*)stack_shape)[19] = (long)56;
  (( long*)stack_shape)[20] = (long)56;
  (( long*)stack_shape)[21] = (long)3136;
  (( long*)stack_shape)[22] = (long)56;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)56;
  (( long*)stack_shape)[8] = (long)56;
  (( long*)stack_shape)[9] = (long)3136;
  (( long*)stack_shape)[10] = (long)56;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_24( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 58) * 58)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 32; ++i1) {
    for (int i2 = 0; i2 < 58; ++i2) {
      for (int i3 = 0; i3 < 58; ++i3) {
        (( float*)PaddedInput)[((((i1 * 58) + i2) * 58) + i3)] = (((((1 <= i2) && (i2 < 57)) && (1 <= i3)) && (i3 < 57)) ? input0[(((((i1 * 56) + i2) * 56) + i3) + -57)] : 0.000000e+00f);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 32; ++c) {
    (( long*)stack_shape)[0] = (long)58;
    (( long*)stack_shape)[1] = (long)58;
    (( long*)stack_shape)[2] = (long)58;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 3364) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)56;
    (( long*)stack_shape)[9] = (long)56;
    (( long*)stack_shape)[10] = (long)56;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 3136) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)32;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)32;
  (( long*)stack_shape)[19] = (long)56;
  (( long*)stack_shape)[20] = (long)56;
  (( long*)stack_shape)[21] = (long)3136;
  (( long*)stack_shape)[22] = (long)56;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)56;
  (( long*)stack_shape)[8] = (long)56;
  (( long*)stack_shape)[9] = (long)3136;
  (( long*)stack_shape)[10] = (long)56;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_25( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 32; ++i1) {
    for (int i2 = 0; i2 < 56; ++i2) {
      for (int i3 = 0; i3 < 56; ++i3) {
        (( float*)pad_temp)[((((i1 * 56) + i2) * 56) + i3)] = input0[((((i1 * 56) + i2) * 56) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)32;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)32;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)32;
  (( long*)stack_shape)[15] = (long)56;
  (( long*)stack_shape)[16] = (long)56;
  (( long*)stack_shape)[17] = (long)3136;
  (( long*)stack_shape)[18] = (long)56;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 56) * 56)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)32;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)32;
  (( long*)stack_shape)[19] = (long)56;
  (( long*)stack_shape)[20] = (long)56;
  (( long*)stack_shape)[21] = (long)3136;
  (( long*)stack_shape)[22] = (long)56;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)56;
  (( long*)stack_shape)[2] = (long)56;
  (( long*)stack_shape)[3] = (long)3136;
  (( long*)stack_shape)[4] = (long)56;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)56;
  (( long*)stack_shape)[8] = (long)56;
  (( long*)stack_shape)[9] = (long)3136;
  (( long*)stack_shape)[10] = (long)56;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_26( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 57) * 57)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 32; ++i1) {
    for (int i2 = 0; i2 < 57; ++i2) {
      for (int i3 = 0; i3 < 57; ++i3) {
        (( float*)PaddedInput)[((((i1 * 57) + i2) * 57) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 56) + i2) * 56) + i3) + -57)]);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 28) * 28)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 32; ++c) {
    (( long*)stack_shape)[0] = (long)57;
    (( long*)stack_shape)[1] = (long)57;
    (( long*)stack_shape)[2] = (long)57;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 3249) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)28;
    (( long*)stack_shape)[9] = (long)28;
    (( long*)stack_shape)[10] = (long)28;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 784) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 28) * 28)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)32;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)32;
  (( long*)stack_shape)[19] = (long)28;
  (( long*)stack_shape)[20] = (long)28;
  (( long*)stack_shape)[21] = (long)784;
  (( long*)stack_shape)[22] = (long)28;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)32;
  (( long*)stack_shape)[7] = (long)28;
  (( long*)stack_shape)[8] = (long)28;
  (( long*)stack_shape)[9] = (long)784;
  (( long*)stack_shape)[10] = (long)28;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_27( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 32) * 28) * 28)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 32; ++i1) {
    for (int i2 = 0; i2 < 28; ++i2) {
      for (int i3 = 0; i3 < 28; ++i3) {
        (( float*)pad_temp)[((((i1 * 28) + i2) * 28) + i3)] = input0[((((i1 * 28) + i2) * 28) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)32;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)32;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)32;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)64;
  (( long*)stack_shape)[15] = (long)28;
  (( long*)stack_shape)[16] = (long)28;
  (( long*)stack_shape)[17] = (long)784;
  (( long*)stack_shape)[18] = (long)28;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)64;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)64;
  (( long*)stack_shape)[19] = (long)28;
  (( long*)stack_shape)[20] = (long)28;
  (( long*)stack_shape)[21] = (long)784;
  (( long*)stack_shape)[22] = (long)28;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)28;
  (( long*)stack_shape)[8] = (long)28;
  (( long*)stack_shape)[9] = (long)784;
  (( long*)stack_shape)[10] = (long)28;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_28( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 30) * 30)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 64; ++i1) {
    for (int i2 = 0; i2 < 30; ++i2) {
      for (int i3 = 0; i3 < 30; ++i3) {
        (( float*)PaddedInput)[((((i1 * 30) + i2) * 30) + i3)] = (((((1 <= i2) && (i2 < 29)) && (1 <= i3)) && (i3 < 29)) ? input0[(((((i1 * 28) + i2) * 28) + i3) + -29)] : 0.000000e+00f);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 64; ++c) {
    (( long*)stack_shape)[0] = (long)30;
    (( long*)stack_shape)[1] = (long)30;
    (( long*)stack_shape)[2] = (long)30;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 900) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)28;
    (( long*)stack_shape)[9] = (long)28;
    (( long*)stack_shape)[10] = (long)28;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 784) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)64;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)64;
  (( long*)stack_shape)[19] = (long)28;
  (( long*)stack_shape)[20] = (long)28;
  (( long*)stack_shape)[21] = (long)784;
  (( long*)stack_shape)[22] = (long)28;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)28;
  (( long*)stack_shape)[8] = (long)28;
  (( long*)stack_shape)[9] = (long)784;
  (( long*)stack_shape)[10] = (long)28;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_29( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 64; ++i1) {
    for (int i2 = 0; i2 < 28; ++i2) {
      for (int i3 = 0; i3 < 28; ++i3) {
        (( float*)pad_temp)[((((i1 * 28) + i2) * 28) + i3)] = input0[((((i1 * 28) + i2) * 28) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)64;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)64;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)64;
  (( long*)stack_shape)[15] = (long)28;
  (( long*)stack_shape)[16] = (long)28;
  (( long*)stack_shape)[17] = (long)784;
  (( long*)stack_shape)[18] = (long)28;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 28) * 28)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)64;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)64;
  (( long*)stack_shape)[19] = (long)28;
  (( long*)stack_shape)[20] = (long)28;
  (( long*)stack_shape)[21] = (long)784;
  (( long*)stack_shape)[22] = (long)28;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)28;
  (( long*)stack_shape)[2] = (long)28;
  (( long*)stack_shape)[3] = (long)784;
  (( long*)stack_shape)[4] = (long)28;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)28;
  (( long*)stack_shape)[8] = (long)28;
  (( long*)stack_shape)[9] = (long)784;
  (( long*)stack_shape)[10] = (long)28;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_30( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 29) * 29)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 64; ++i1) {
    for (int i2 = 0; i2 < 29; ++i2) {
      for (int i3 = 0; i3 < 29; ++i3) {
        (( float*)PaddedInput)[((((i1 * 29) + i2) * 29) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 28) + i2) * 28) + i3) + -29)]);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 14) * 14)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 64; ++c) {
    (( long*)stack_shape)[0] = (long)29;
    (( long*)stack_shape)[1] = (long)29;
    (( long*)stack_shape)[2] = (long)29;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 841) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)14;
    (( long*)stack_shape)[9] = (long)14;
    (( long*)stack_shape)[10] = (long)14;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 196) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 14) * 14)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)64;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)64;
  (( long*)stack_shape)[19] = (long)14;
  (( long*)stack_shape)[20] = (long)14;
  (( long*)stack_shape)[21] = (long)196;
  (( long*)stack_shape)[22] = (long)14;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)64;
  (( long*)stack_shape)[7] = (long)14;
  (( long*)stack_shape)[8] = (long)14;
  (( long*)stack_shape)[9] = (long)196;
  (( long*)stack_shape)[10] = (long)14;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_31( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 64) * 14) * 14)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 64; ++i1) {
    for (int i2 = 0; i2 < 14; ++i2) {
      for (int i3 = 0; i3 < 14; ++i3) {
        (( float*)pad_temp)[((((i1 * 14) + i2) * 14) + i3)] = input0[((((i1 * 14) + i2) * 14) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)64;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)64;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)64;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)128;
  (( long*)stack_shape)[15] = (long)14;
  (( long*)stack_shape)[16] = (long)14;
  (( long*)stack_shape)[17] = (long)196;
  (( long*)stack_shape)[18] = (long)14;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)128;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)128;
  (( long*)stack_shape)[19] = (long)14;
  (( long*)stack_shape)[20] = (long)14;
  (( long*)stack_shape)[21] = (long)196;
  (( long*)stack_shape)[22] = (long)14;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)14;
  (( long*)stack_shape)[8] = (long)14;
  (( long*)stack_shape)[9] = (long)196;
  (( long*)stack_shape)[10] = (long)14;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_32( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 16) * 16)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 128; ++i1) {
    for (int i2 = 0; i2 < 16; ++i2) {
      for (int i3 = 0; i3 < 16; ++i3) {
        (( float*)PaddedInput)[((((i1 * 16) + i2) * 16) + i3)] = (((((1 <= i2) && (i2 < 15)) && (1 <= i3)) && (i3 < 15)) ? input0[(((((i1 * 14) + i2) * 14) + i3) + -15)] : 0.000000e+00f);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 128; ++c) {
    (( long*)stack_shape)[0] = (long)16;
    (( long*)stack_shape)[1] = (long)16;
    (( long*)stack_shape)[2] = (long)16;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 256) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)14;
    (( long*)stack_shape)[9] = (long)14;
    (( long*)stack_shape)[10] = (long)14;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 196) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)128;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)128;
  (( long*)stack_shape)[19] = (long)14;
  (( long*)stack_shape)[20] = (long)14;
  (( long*)stack_shape)[21] = (long)196;
  (( long*)stack_shape)[22] = (long)14;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)14;
  (( long*)stack_shape)[8] = (long)14;
  (( long*)stack_shape)[9] = (long)196;
  (( long*)stack_shape)[10] = (long)14;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_33( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 128; ++i1) {
    for (int i2 = 0; i2 < 14; ++i2) {
      for (int i3 = 0; i3 < 14; ++i3) {
        (( float*)pad_temp)[((((i1 * 14) + i2) * 14) + i3)] = input0[((((i1 * 14) + i2) * 14) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)128;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)128;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)128;
  (( long*)stack_shape)[15] = (long)14;
  (( long*)stack_shape)[16] = (long)14;
  (( long*)stack_shape)[17] = (long)196;
  (( long*)stack_shape)[18] = (long)14;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 14) * 14)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)128;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)128;
  (( long*)stack_shape)[19] = (long)14;
  (( long*)stack_shape)[20] = (long)14;
  (( long*)stack_shape)[21] = (long)196;
  (( long*)stack_shape)[22] = (long)14;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)14;
  (( long*)stack_shape)[2] = (long)14;
  (( long*)stack_shape)[3] = (long)196;
  (( long*)stack_shape)[4] = (long)14;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)14;
  (( long*)stack_shape)[8] = (long)14;
  (( long*)stack_shape)[9] = (long)196;
  (( long*)stack_shape)[10] = (long)14;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_34( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 15) * 15)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 128; ++i1) {
    for (int i2 = 0; i2 < 15; ++i2) {
      for (int i3 = 0; i3 < 15; ++i3) {
        (( float*)PaddedInput)[((((i1 * 15) + i2) * 15) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 14) + i2) * 14) + i3) + -15)]);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 7) * 7)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 128; ++c) {
    (( long*)stack_shape)[0] = (long)15;
    (( long*)stack_shape)[1] = (long)15;
    (( long*)stack_shape)[2] = (long)15;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 225) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)7;
    (( long*)stack_shape)[9] = (long)7;
    (( long*)stack_shape)[10] = (long)7;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 49) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 7) * 7)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)128;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)128;
  (( long*)stack_shape)[19] = (long)7;
  (( long*)stack_shape)[20] = (long)7;
  (( long*)stack_shape)[21] = (long)49;
  (( long*)stack_shape)[22] = (long)7;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)128;
  (( long*)stack_shape)[7] = (long)7;
  (( long*)stack_shape)[8] = (long)7;
  (( long*)stack_shape)[9] = (long)49;
  (( long*)stack_shape)[10] = (long)7;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_35( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 128) * 7) * 7)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 128; ++i1) {
    for (int i2 = 0; i2 < 7; ++i2) {
      for (int i3 = 0; i3 < 7; ++i3) {
        (( float*)pad_temp)[((((i1 * 7) + i2) * 7) + i3)] = input0[((((i1 * 7) + i2) * 7) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)128;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)128;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)128;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)256;
  (( long*)stack_shape)[15] = (long)7;
  (( long*)stack_shape)[16] = (long)7;
  (( long*)stack_shape)[17] = (long)49;
  (( long*)stack_shape)[18] = (long)7;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)256;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)256;
  (( long*)stack_shape)[19] = (long)7;
  (( long*)stack_shape)[20] = (long)7;
  (( long*)stack_shape)[21] = (long)49;
  (( long*)stack_shape)[22] = (long)7;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)7;
  (( long*)stack_shape)[8] = (long)7;
  (( long*)stack_shape)[9] = (long)49;
  (( long*)stack_shape)[10] = (long)7;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_36( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* PaddedInput = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 9) * 9)), 2, 32);
  if (PaddedInput == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 256; ++i1) {
    for (int i2 = 0; i2 < 9; ++i2) {
      for (int i3 = 0; i3 < 9; ++i3) {
        (( float*)PaddedInput)[((((i1 * 9) + i2) * 9) + i3)] = (((((1 <= i2) && (i2 < 8)) && (1 <= i3)) && (i3 < 8)) ? input0[(((((i1 * 7) + i2) * 7) + i3) + -8)] : 0.000000e+00f);
      }
    }
  }
  void* DepthwiseConv2d = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (DepthwiseConv2d == NULL) {
    (void)assert(0);
  }
  for (int c = 0; c < 256; ++c) {
    (( long*)stack_shape)[0] = (long)9;
    (( long*)stack_shape)[1] = (long)9;
    (( long*)stack_shape)[2] = (long)9;
    (( long*)stack_shape)[3] = (long)1;
    (((TVMArray*)stack_array)[0].data) = PaddedInput;
    (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
    (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 2);
    (((TVMArray*)stack_array)[0].ndim) = 2;
    (((TVMArray*)stack_array)[0].byte_offset) = ((unsigned long)((c * 81) * 4));
    (( long*)stack_shape)[4] = (long)3;
    (( long*)stack_shape)[5] = (long)3;
    (( long*)stack_shape)[6] = (long)3;
    (( long*)stack_shape)[7] = (long)1;
    (((TVMArray*)stack_array)[1].data) = input1;
    (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 4);
    (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 6);
    (((TVMArray*)stack_array)[1].ndim) = 2;
    (((TVMArray*)stack_array)[1].byte_offset) = ((unsigned long)((c * 9) * 4));
    (( long*)stack_shape)[8] = (long)7;
    (( long*)stack_shape)[9] = (long)7;
    (( long*)stack_shape)[10] = (long)7;
    (( long*)stack_shape)[11] = (long)1;
    (((TVMArray*)stack_array)[2].data) = DepthwiseConv2d;
    (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 8);
    (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 10);
    (((TVMArray*)stack_array)[2].ndim) = 2;
    (((TVMArray*)stack_array)[2].byte_offset) = ((unsigned long)((c * 49) * 4));
    (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
    (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
    (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
    (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  }
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = DepthwiseConv2d;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)256;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)256;
  (( long*)stack_shape)[19] = (long)7;
  (( long*)stack_shape)[20] = (long)7;
  (( long*)stack_shape)[21] = (long)49;
  (( long*)stack_shape)[22] = (long)7;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)7;
  (( long*)stack_shape)[8] = (long)7;
  (( long*)stack_shape)[9] = (long)49;
  (( long*)stack_shape)[10] = (long)7;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, DepthwiseConv2d) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, PaddedInput) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_37( void* args,  void* arg_type_ids, int num_args) {
  void* stack_value = malloc(sizeof(TVMValue) * 5);;
  void* stack_array = malloc(sizeof(DLTensor) * 4);;
  void* stack_shape = malloc(sizeof(long) * 24);;
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  void* arg2 = (((TVMValue*)args)[2].v_handle);
  int arg2_code = (( int*)arg_type_ids)[2];
  void* arg3 = (((TVMValue*)args)[3].v_handle);
  int arg3_code = (( int*)arg_type_ids)[3];
  void* arg4 = (((TVMValue*)args)[4].v_handle);
  int arg4_code = (( int*)arg_type_ids)[4];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
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
  float* input3 = (float*)(((TVMArray*)arg3)[0].data);
  long* arg3_shape = (long*)(((TVMArray*)arg3)[0].shape);
  long* arg3_strides = (long*)(((TVMArray*)arg3)[0].strides);
  if (!(arg3_strides == NULL)) {
  }
  float* relu_t = (float*)(((TVMArray*)arg4)[0].data);
  long* arg4_shape = (long*)(((TVMArray*)arg4)[0].shape);
  long* arg4_strides = (long*)(((TVMArray*)arg4)[0].strides);
  if (!(arg4_strides == NULL)) {
  }
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 256; ++i1) {
    for (int i2 = 0; i2 < 7; ++i2) {
      for (int i3 = 0; i3 < 7; ++i3) {
        (( float*)pad_temp)[((((i1 * 7) + i2) * 7) + i3)] = input0[((((i1 * 7) + i2) * 7) + i3)];
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = pad_temp;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)256;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)256;
  (( long*)stack_shape)[11] = (long)1;
  (( long*)stack_shape)[12] = (long)1;
  (( long*)stack_shape)[13] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input1;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 10);
  (((TVMArray*)stack_array)[1].ndim) = 4;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[14] = (long)256;
  (( long*)stack_shape)[15] = (long)7;
  (( long*)stack_shape)[16] = (long)7;
  (( long*)stack_shape)[17] = (long)49;
  (( long*)stack_shape)[18] = (long)7;
  (( long*)stack_shape)[19] = (long)1;
  (((TVMArray*)stack_array)[2].data) = compute;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 14);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 17);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (void)TVMFuncCall(conv2d,((TVMValue*)stack_value)[0],3-0);
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 7) * 7)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = compute;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)1;
  (( long*)stack_shape)[8] = (long)1;
  (( long*)stack_shape)[9] = (long)1;
  (( long*)stack_shape)[10] = (long)1;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = input2;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[12] = (long)256;
  (( long*)stack_shape)[13] = (long)1;
  (( long*)stack_shape)[14] = (long)1;
  (( long*)stack_shape)[15] = (long)1;
  (( long*)stack_shape)[16] = (long)1;
  (( long*)stack_shape)[17] = (long)1;
  (((TVMArray*)stack_array)[2].data) = input3;
  (((TVMArray*)stack_array)[2].shape) = ((long *)stack_shape + 12);
  (((TVMArray*)stack_array)[2].strides) = ((long *)stack_shape + 15);
  (((TVMArray*)stack_array)[2].ndim) = 3;
  (((TVMArray*)stack_array)[2].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[18] = (long)256;
  (( long*)stack_shape)[19] = (long)7;
  (( long*)stack_shape)[20] = (long)7;
  (( long*)stack_shape)[21] = (long)49;
  (( long*)stack_shape)[22] = (long)7;
  (( long*)stack_shape)[23] = (long)1;
  (((TVMArray*)stack_array)[3].data) = tensor;
  (((TVMArray*)stack_array)[3].shape) = ((long *)stack_shape + 18);
  (((TVMArray*)stack_array)[3].strides) = ((long *)stack_shape + 21);
  (((TVMArray*)stack_array)[3].ndim) = 3;
  (((TVMArray*)stack_array)[3].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (((TVMValue*)stack_value)[2].v_handle) = (((TVMArray*)stack_array) + 2);
  (((TVMValue*)stack_value)[3].v_handle) = (((TVMArray*)stack_array) + 3);
  (void)TVMFuncCall(norm2d,((TVMValue*)stack_value)[0],4-0);
  (( long*)stack_shape)[0] = (long)256;
  (( long*)stack_shape)[1] = (long)7;
  (( long*)stack_shape)[2] = (long)7;
  (( long*)stack_shape)[3] = (long)49;
  (( long*)stack_shape)[4] = (long)7;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)256;
  (( long*)stack_shape)[7] = (long)7;
  (( long*)stack_shape)[8] = (long)7;
  (( long*)stack_shape)[9] = (long)49;
  (( long*)stack_shape)[10] = (long)7;
  (( long*)stack_shape)[11] = (long)1;
  (((TVMArray*)stack_array)[1].data) = relu_t;
  (((TVMArray*)stack_array)[1].shape) = ((long *)stack_shape + 6);
  (((TVMArray*)stack_array)[1].strides) = ((long *)stack_shape + 9);
  (((TVMArray*)stack_array)[1].ndim) = 3;
  (((TVMArray*)stack_array)[1].byte_offset) = (unsigned long)0;
  (((TVMValue*)stack_value)[0].v_handle) = (((TVMArray*)stack_array) + 0);
  (((TVMValue*)stack_value)[1].v_handle) = (((TVMArray*)stack_array) + 1);
  (void)TVMFuncCall(relu2d,((TVMValue*)stack_value)[0],2-0);
  if (TVMBackendFreeWorkspace(13, dev_id, tensor) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute) != 0) {
    (void)assert(0);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, pad_temp) != 0) {
    (void)assert(0);
  }
}

extern "C" void fuse_global_avg_pool2d_1( void* args,  void* arg_type_ids, int num_args) {
  void* arg0 = (((TVMValue*)args)[0].v_handle);
  int arg0_code = (( int*)arg_type_ids)[0];
  void* arg1 = (((TVMValue*)args)[1].v_handle);
  int arg1_code = (( int*)arg_type_ids)[1];
  float* input0 = (float*)(((TVMArray*)arg0)[0].data);
  long* arg0_shape = (long*)(((TVMArray*)arg0)[0].shape);
  long* arg0_strides = (long*)(((TVMArray*)arg0)[0].strides);
  if (!(arg0_strides == NULL)) {
  }
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* tensor = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  void* tensor1 = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 256) * 1) * 1)), 2, 32);
  if (tensor1 == NULL) {
    (void)assert(0);
  }
  for (int ax1 = 0; ax1 < 256; ++ax1) {
    (( float*)tensor1)[ax1] = 0.000000e+00f;
    for (int rv = 0; rv < 7; ++rv) {
      for (int rv1 = 0; rv1 < 7; ++rv1) {
        (( float*)tensor1)[ax1] = ((( float*)tensor1)[ax1] + input0[((((ax1 * 7) + rv) * 7) + rv1)]);
      }
    }
  }
  for (int ax11 = 0; ax11 < 256; ++ax11) {
    tensor[ax11] = ((( float*)tensor1)[ax11] * 2.040816e-02f);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, tensor1) != 0) {
    (void)assert(0);
  }
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
  int dev_id = (((TVMArray*)arg0)[0].ctx.device_id);
  float* tensor = (float*)(((TVMArray*)arg1)[0].data);
  long* arg1_shape = (long*)(((TVMArray*)arg1)[0].shape);
  long* arg1_strides = (long*)(((TVMArray*)arg1)[0].strides);
  if (!(arg1_strides == NULL)) {
  }
  for (int ax1 = 0; ax1 < 256; ++ax1) {
    tensor[ax1] = input0[ax1];
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
  void* compute1 = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((4 * 1) * 1000)), 2, 32);
  if (compute1 == NULL) {
    (void)assert(0);
  }
  for (int j = 0; j < 1000; ++j) {
    (( float*)compute1)[j] = 0.000000e+00f;
    for (int k = 0; k < 256; ++k) {
      (( float*)compute1)[j] = ((( float*)compute1)[j] + (input0[k] * input1[((j * 256) + k)]));
    }
  }
  for (int j1 = 0; j1 < 1000; ++j1) {
    compute[j1] = ((( float*)compute1)[j1] + input2[j1]);
  }
  if (TVMBackendFreeWorkspace(13, dev_id, compute1) != 0) {
    (void)assert(0);
  }
}

