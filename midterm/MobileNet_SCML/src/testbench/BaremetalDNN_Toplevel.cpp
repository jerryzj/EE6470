#include "BaremetalDNN_Op.h"
#include "runtime.h"
void BaremetalDNN_toplevel(
float* ret /* float[1][1000] */,
	const float* data /* float[1][3][224][224] */ ,
	const float* mobilenet0_conv0_weight /* float[8][3][3][3] */ ,
	const float* batch_norm0_gamma_mul_div_expand /* float[8][1][1] */ ,
	const float* batch_norm0_add_beta_expand /* float[8][1][1] */ ,
	const float* mobilenet0_conv1_weight /* float[8][1][3][3] */ ,
	const float* batch_norm1_gamma_mul_div_expand /* float[8][1][1] */ ,
	const float* batch_norm1_add_beta_expand /* float[8][1][1] */ ,
	const float* mobilenet0_conv2_weight /* float[16][8][1][1] */ ,
	const float* batch_norm2_gamma_mul_div_expand /* float[16][1][1] */ ,
	const float* batch_norm2_add_beta_expand /* float[16][1][1] */ ,
	const float* mobilenet0_conv3_weight /* float[16][1][3][3] */ ,
	const float* batch_norm3_gamma_mul_div_expand /* float[16][1][1] */ ,
	const float* batch_norm3_add_beta_expand /* float[16][1][1] */ ,
	const float* mobilenet0_conv4_weight /* float[32][16][1][1] */ ,
	const float* batch_norm4_gamma_mul_div_expand /* float[32][1][1] */ ,
	const float* batch_norm4_add_beta_expand /* float[32][1][1] */ ,
	const float* mobilenet0_conv5_weight /* float[32][1][3][3] */ ,
	const float* batch_norm5_gamma_mul_div_expand /* float[32][1][1] */ ,
	const float* batch_norm5_add_beta_expand /* float[32][1][1] */ ,
	const float* mobilenet0_conv6_weight /* float[32][32][1][1] */ ,
	const float* batch_norm6_gamma_mul_div_expand /* float[32][1][1] */ ,
	const float* batch_norm6_add_beta_expand /* float[32][1][1] */ ,
	const float* mobilenet0_conv7_weight /* float[32][1][3][3] */ ,
	const float* batch_norm7_gamma_mul_div_expand /* float[32][1][1] */ ,
	const float* batch_norm7_add_beta_expand /* float[32][1][1] */ ,
	const float* mobilenet0_conv8_weight /* float[64][32][1][1] */ ,
	const float* batch_norm8_gamma_mul_div_expand /* float[64][1][1] */ ,
	const float* batch_norm8_add_beta_expand /* float[64][1][1] */ ,
	const float* mobilenet0_conv9_weight /* float[64][1][3][3] */ ,
	const float* batch_norm9_gamma_mul_div_expand /* float[64][1][1] */ ,
	const float* batch_norm9_add_beta_expand /* float[64][1][1] */ ,
	const float* mobilenet0_conv10_weight /* float[64][64][1][1] */ ,
	const float* batch_norm10_gamma_mul_div_expand /* float[64][1][1] */ ,
	const float* batch_norm10_add_beta_expand /* float[64][1][1] */ ,
	const float* mobilenet0_conv11_weight /* float[64][1][3][3] */ ,
	const float* batch_norm11_gamma_mul_div_expand /* float[64][1][1] */ ,
	const float* batch_norm11_add_beta_expand /* float[64][1][1] */ ,
	const float* mobilenet0_conv12_weight /* float[128][64][1][1] */ ,
	const float* batch_norm12_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm12_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv13_weight /* float[128][1][3][3] */ ,
	const float* batch_norm13_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm13_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv14_weight /* float[128][128][1][1] */ ,
	const float* batch_norm14_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm14_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv15_weight /* float[128][1][3][3] */ ,
	const float* batch_norm15_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm15_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv16_weight /* float[128][128][1][1] */ ,
	const float* batch_norm16_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm16_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv17_weight /* float[128][1][3][3] */ ,
	const float* batch_norm17_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm17_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv18_weight /* float[128][128][1][1] */ ,
	const float* batch_norm18_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm18_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv19_weight /* float[128][1][3][3] */ ,
	const float* batch_norm19_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm19_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv20_weight /* float[128][128][1][1] */ ,
	const float* batch_norm20_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm20_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv21_weight /* float[128][1][3][3] */ ,
	const float* batch_norm21_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm21_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv22_weight /* float[128][128][1][1] */ ,
	const float* batch_norm22_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm22_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv23_weight /* float[128][1][3][3] */ ,
	const float* batch_norm23_gamma_mul_div_expand /* float[128][1][1] */ ,
	const float* batch_norm23_add_beta_expand /* float[128][1][1] */ ,
	const float* mobilenet0_conv24_weight /* float[256][128][1][1] */ ,
	const float* batch_norm24_gamma_mul_div_expand /* float[256][1][1] */ ,
	const float* batch_norm24_add_beta_expand /* float[256][1][1] */ ,
	const float* mobilenet0_conv25_weight /* float[256][1][3][3] */ ,
	const float* batch_norm25_gamma_mul_div_expand /* float[256][1][1] */ ,
	const float* batch_norm25_add_beta_expand /* float[256][1][1] */ ,
	const float* mobilenet0_conv26_weight /* float[256][256][1][1] */ ,
	const float* batch_norm26_gamma_mul_div_expand /* float[256][1][1] */ ,
	const float* batch_norm26_add_beta_expand /* float[256][1][1] */ ,
	const float* mobilenet0_dense0_weight /* float[1000][256] */ ,
	const float* mobilenet0_dense0_bias /* float[1000] */ ){
#include "BaremetalDNN_Tensor.h"
float* LocalBuf0 = new float[200704];
float* LocalBuf1 = new float[200704];
// tvmop: 4 : relu0
relu0_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_19((void*) relu0_tvmval,(void*) relu0_typeid,5);
// tvmop: 8 : relu1
relu1_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_20((void*) relu1_tvmval,(void*) relu1_typeid,5);
// tvmop: 12 : relu2
relu2_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_21((void*) relu2_tvmval,(void*) relu2_typeid,5);
// tvmop: 16 : relu3
relu3_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_22((void*) relu3_tvmval,(void*) relu3_typeid,5);
// tvmop: 20 : relu4
relu4_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_23((void*) relu4_tvmval,(void*) relu4_typeid,5);
// tvmop: 24 : relu5
relu5_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_24((void*) relu5_tvmval,(void*) relu5_typeid,5);
// tvmop: 28 : relu6
relu6_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_25((void*) relu6_tvmval,(void*) relu6_typeid,5);
// tvmop: 32 : relu7
relu7_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_26((void*) relu7_tvmval,(void*) relu7_typeid,5);
// tvmop: 36 : relu8
relu8_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_27((void*) relu8_tvmval,(void*) relu8_typeid,5);
// tvmop: 40 : relu9
relu9_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_28((void*) relu9_tvmval,(void*) relu9_typeid,5);
// tvmop: 44 : relu10
relu10_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_29((void*) relu10_tvmval,(void*) relu10_typeid,5);
// tvmop: 48 : relu11
relu11_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_30((void*) relu11_tvmval,(void*) relu11_typeid,5);
// tvmop: 52 : relu12
relu12_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_31((void*) relu12_tvmval,(void*) relu12_typeid,5);
// tvmop: 56 : relu13
relu13_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_32((void*) relu13_tvmval,(void*) relu13_typeid,5);
// tvmop: 60 : relu14
relu14_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_33((void*) relu14_tvmval,(void*) relu14_typeid,5);
// tvmop: 64 : relu15
relu15_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_32((void*) relu15_tvmval,(void*) relu15_typeid,5);
// tvmop: 68 : relu16
relu16_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_33((void*) relu16_tvmval,(void*) relu16_typeid,5);
// tvmop: 72 : relu17
relu17_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_32((void*) relu17_tvmval,(void*) relu17_typeid,5);
// tvmop: 76 : relu18
relu18_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_33((void*) relu18_tvmval,(void*) relu18_typeid,5);
// tvmop: 80 : relu19
relu19_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_32((void*) relu19_tvmval,(void*) relu19_typeid,5);
// tvmop: 84 : relu20
relu20_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_33((void*) relu20_tvmval,(void*) relu20_typeid,5);
// tvmop: 88 : relu21
relu21_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_32((void*) relu21_tvmval,(void*) relu21_typeid,5);
// tvmop: 92 : relu22
relu22_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_33((void*) relu22_tvmval,(void*) relu22_typeid,5);
// tvmop: 96 : relu23
relu23_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_34((void*) relu23_tvmval,(void*) relu23_typeid,5);
// tvmop: 100 : relu24
relu24_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_35((void*) relu24_tvmval,(void*) relu24_typeid,5);
// tvmop: 104 : relu25
relu25_tensor.data = (void*) LocalBuf1;
fuse_conv2d_broadcast_mul_broadcast_add_relu_36((void*) relu25_tvmval,(void*) relu25_typeid,5);
// tvmop: 108 : relu26
relu26_tensor.data = (void*) LocalBuf0;
fuse_conv2d_broadcast_mul_broadcast_add_relu_37((void*) relu26_tvmval,(void*) relu26_typeid,5);
// tvmop: 109 : global_avg_pool2d0
global_avg_pool2d0_tensor.data = (void*) LocalBuf1;
fuse_global_avg_pool2d_1((void*) global_avg_pool2d0_tvmval,(void*) global_avg_pool2d0_typeid,2);
// tvmop: 110 : flatten0
flatten0_tensor.data = (void*) LocalBuf0;
fuse_reshape_flatten_1((void*) flatten0_tvmval,(void*) flatten0_typeid,2);
// tvmop: 113 : dense0
dense0_tensor.data = (void*) ret;
fuse_dense_1((void*) dense0_tvmval,(void*) dense0_typeid,4);

delete[] LocalBuf0;
delete[] LocalBuf1;
}