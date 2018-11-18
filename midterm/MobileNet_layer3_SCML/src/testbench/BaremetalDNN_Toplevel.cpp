#include "BaremetalDNN_Op.h"
#include "runtime.h"
void BaremetalDNN_toplevel(
float* ret /* float[1][8][8][8] */,
	const float* data /* float[1][3][16][16] */ ,
	const float* mobilenet0_conv0_weight /* float[8][3][3][3] */ ,
	const float* batch_norm0_gamma_mul_div_expand /* float[8][1][1] */ ,
	const float* batch_norm0_add_beta_expand /* float[8][1][1] */ ){
#include "BaremetalDNN_Tensor.h"
float* LocalBuf0 = new float[512];
float* LocalBuf1 = new float[512];
// tvmop: 4 : relu0
relu0_tensor.data = (void*) ret;
fuse_conv2d_broadcast_mul_broadcast_add_relu_1((void*) relu0_tvmval,(void*) relu0_typeid,5);

delete[] LocalBuf0;
delete[] LocalBuf1;
}