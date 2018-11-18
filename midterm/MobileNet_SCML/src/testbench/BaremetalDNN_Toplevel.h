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
	const float* mobilenet0_dense0_bias /* float[1000] */ );