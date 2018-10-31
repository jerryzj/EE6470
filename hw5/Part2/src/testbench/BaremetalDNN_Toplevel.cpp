#include "BaremetalDNN_Op.h"
#include "runtime.h"
void BaremetalDNN_toplevel(
float* ret /* float[1][10] */,
	const float* data /* float[1][1][14][14] */ ,
	const float* net0_conv0_weight /* float[4][1][3][3] */ ,
	const float* net0_conv0_bias /* float[4] */ ,
	const float* net0_conv1_weight /* float[8][4][3][3] */ ,
	const float* net0_conv1_bias /* float[8] */ ,
	const float* net0_dense0_weight /* float[10][32] */ ,
	const float* net0_dense0_bias /* float[10] */ ){
#include "BaremetalDNN_Tensor.h"
float* LocalBuf0 = new float[576];
float* LocalBuf1 = new float[576];
// tvmop: 3 : relu0
relu0_tensor.data = (void*) LocalBuf0;
fuse_conv2d_relu_2((void*) relu0_tvmval,(void*) relu0_typeid,4);
// tvmop: 4 : max_pool2d0
max_pool2d0_tensor.data = (void*) LocalBuf1;
fuse_max_pool2d_2((void*) max_pool2d0_tvmval,(void*) max_pool2d0_typeid,2);
// tvmop: 7 : relu1
relu1_tensor.data = (void*) LocalBuf0;
fuse_conv2d_relu_3((void*) relu1_tvmval,(void*) relu1_typeid,4);
// tvmop: 8 : max_pool2d1
max_pool2d1_tensor.data = (void*) LocalBuf1;
fuse_max_pool2d_3((void*) max_pool2d1_tvmval,(void*) max_pool2d1_typeid,2);
// tvmop: 9 : flatten0
flatten0_tensor.data = (void*) LocalBuf0;
fuse_reshape_flatten_1((void*) flatten0_tvmval,(void*) flatten0_typeid,2);
// tvmop: 12 : dense0
dense0_tensor.data = (void*) ret;
fuse_dense_1((void*) dense0_tvmval,(void*) dense0_typeid,4);

delete[] LocalBuf0;
delete[] LocalBuf1;
}