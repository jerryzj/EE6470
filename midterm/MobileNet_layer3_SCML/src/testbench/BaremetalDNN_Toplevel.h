void BaremetalDNN_toplevel(
float* ret /* float[1][8][8][8] */,
	const float* data /* float[1][3][16][16] */ ,
	const float* mobilenet0_conv0_weight /* float[8][3][3][3] */ ,
	const float* batch_norm0_gamma_mul_div_expand /* float[8][1][1] */ ,
	const float* batch_norm0_add_beta_expand /* float[8][1][1] */ );
