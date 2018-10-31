void BaremetalDNN_toplevel(
float* ret /* float[1][10] */,
	const float* data /* float[1][1][14][14] */ ,
	const float* net0_conv0_weight /* float[4][1][3][3] */ ,
	const float* net0_conv0_bias /* float[4] */ ,
	const float* net0_conv1_weight /* float[8][4][3][3] */ ,
	const float* net0_conv1_bias /* float[8] */ ,
	const float* net0_dense0_weight /* float[10][32] */ ,
	const float* net0_dense0_bias /* float[10] */ );
