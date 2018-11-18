#include <cmath>
#include "runtime.h"
using namespace std;
extern "C" void fuse_conv2d_broadcast_mul_broadcast_add_relu_1( void* args,  void* arg_type_ids, int num_args) {
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
  void* pad_temp = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 3) * 17) * 17)), 2, 32);
  if (pad_temp == NULL) {
    (void)assert(0);
  }
  for (int i1 = 0; i1 < 3; ++i1) {
    for (int i2 = 0; i2 < 17; ++i2) {
      for (int i3 = 0; i3 < 17; ++i3) {
        (( float*)pad_temp)[((((i1 * 17) + i2) * 17) + i3)] = ((min(i2, i3) < 1) ? 0.000000e+00f : input0[(((((i1 * 16) + i2) * 16) + i3) + -17)]);
      }
    }
  }
  void* compute = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 8) * 8)), 2, 32);
  if (compute == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)3;
  (( long*)stack_shape)[1] = (long)17;
  (( long*)stack_shape)[2] = (long)17;
  (( long*)stack_shape)[3] = (long)289;
  (( long*)stack_shape)[4] = (long)17;
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
  (( long*)stack_shape)[15] = (long)8;
  (( long*)stack_shape)[16] = (long)8;
  (( long*)stack_shape)[17] = (long)64;
  (( long*)stack_shape)[18] = (long)8;
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
  void* tensor = TVMBackendAllocWorkspace(13, dev_id, ((unsigned long)((((4 * 1) * 8) * 8) * 8)), 2, 32);
  if (tensor == NULL) {
    (void)assert(0);
  }
  (( long*)stack_shape)[0] = (long)8;
  (( long*)stack_shape)[1] = (long)8;
  (( long*)stack_shape)[2] = (long)8;
  (( long*)stack_shape)[3] = (long)64;
  (( long*)stack_shape)[4] = (long)8;
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
  (( long*)stack_shape)[19] = (long)8;
  (( long*)stack_shape)[20] = (long)8;
  (( long*)stack_shape)[21] = (long)64;
  (( long*)stack_shape)[22] = (long)8;
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
  (( long*)stack_shape)[1] = (long)8;
  (( long*)stack_shape)[2] = (long)8;
  (( long*)stack_shape)[3] = (long)64;
  (( long*)stack_shape)[4] = (long)8;
  (( long*)stack_shape)[5] = (long)1;
  (((TVMArray*)stack_array)[0].data) = tensor;
  (((TVMArray*)stack_array)[0].shape) = ((long *)stack_shape + 0);
  (((TVMArray*)stack_array)[0].strides) = ((long *)stack_shape + 3);
  (((TVMArray*)stack_array)[0].ndim) = 3;
  (((TVMArray*)stack_array)[0].byte_offset) = (unsigned long)0;
  (( long*)stack_shape)[6] = (long)8;
  (( long*)stack_shape)[7] = (long)8;
  (( long*)stack_shape)[8] = (long)8;
  (( long*)stack_shape)[9] = (long)64;
  (( long*)stack_shape)[10] = (long)8;
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

