const int64_t data_shape[4] = {1,3,224,224};
DLTensor data_tensor = {
	(void*)data/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)data_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv0_weight_shape[4] = {8,3,3,3};
DLTensor mobilenet0_conv0_weight_tensor = {
	(void*)mobilenet0_conv0_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv0_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm0_gamma_mul_div_expand_shape[3] = {8,1,1};
DLTensor batch_norm0_gamma_mul_div_expand_tensor = {
	(void*)batch_norm0_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm0_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm0_add_beta_expand_shape[3] = {8,1,1};
DLTensor batch_norm0_add_beta_expand_tensor = {
	(void*)batch_norm0_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm0_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 4 : relu0
// will not be used actually// float[1][8][112][112]
float* relu0 = nullptr;
const int64_t relu0_shape[4] = {1,8,112,112};
DLTensor relu0_tensor = {
	(void*)relu0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv1_weight_shape[4] = {8,1,3,3};
DLTensor mobilenet0_conv1_weight_tensor = {
	(void*)mobilenet0_conv1_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv1_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm1_gamma_mul_div_expand_shape[3] = {8,1,1};
DLTensor batch_norm1_gamma_mul_div_expand_tensor = {
	(void*)batch_norm1_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm1_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm1_add_beta_expand_shape[3] = {8,1,1};
DLTensor batch_norm1_add_beta_expand_tensor = {
	(void*)batch_norm1_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm1_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 8 : relu1
// will not be used actually// float[1][8][112][112]
float* relu1 = nullptr;
const int64_t relu1_shape[4] = {1,8,112,112};
DLTensor relu1_tensor = {
	(void*)relu1/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu1_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv2_weight_shape[4] = {16,8,1,1};
DLTensor mobilenet0_conv2_weight_tensor = {
	(void*)mobilenet0_conv2_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv2_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm2_gamma_mul_div_expand_shape[3] = {16,1,1};
DLTensor batch_norm2_gamma_mul_div_expand_tensor = {
	(void*)batch_norm2_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm2_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm2_add_beta_expand_shape[3] = {16,1,1};
DLTensor batch_norm2_add_beta_expand_tensor = {
	(void*)batch_norm2_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm2_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 12 : relu2
// will not be used actually// float[1][16][112][112]
float* relu2 = nullptr;
const int64_t relu2_shape[4] = {1,16,112,112};
DLTensor relu2_tensor = {
	(void*)relu2/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu2_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv3_weight_shape[4] = {16,1,3,3};
DLTensor mobilenet0_conv3_weight_tensor = {
	(void*)mobilenet0_conv3_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv3_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm3_gamma_mul_div_expand_shape[3] = {16,1,1};
DLTensor batch_norm3_gamma_mul_div_expand_tensor = {
	(void*)batch_norm3_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm3_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm3_add_beta_expand_shape[3] = {16,1,1};
DLTensor batch_norm3_add_beta_expand_tensor = {
	(void*)batch_norm3_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm3_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 16 : relu3
// will not be used actually// float[1][16][56][56]
float* relu3 = nullptr;
const int64_t relu3_shape[4] = {1,16,56,56};
DLTensor relu3_tensor = {
	(void*)relu3/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu3_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv4_weight_shape[4] = {32,16,1,1};
DLTensor mobilenet0_conv4_weight_tensor = {
	(void*)mobilenet0_conv4_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv4_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm4_gamma_mul_div_expand_shape[3] = {32,1,1};
DLTensor batch_norm4_gamma_mul_div_expand_tensor = {
	(void*)batch_norm4_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm4_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm4_add_beta_expand_shape[3] = {32,1,1};
DLTensor batch_norm4_add_beta_expand_tensor = {
	(void*)batch_norm4_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm4_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 20 : relu4
// will not be used actually// float[1][32][56][56]
float* relu4 = nullptr;
const int64_t relu4_shape[4] = {1,32,56,56};
DLTensor relu4_tensor = {
	(void*)relu4/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu4_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv5_weight_shape[4] = {32,1,3,3};
DLTensor mobilenet0_conv5_weight_tensor = {
	(void*)mobilenet0_conv5_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv5_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm5_gamma_mul_div_expand_shape[3] = {32,1,1};
DLTensor batch_norm5_gamma_mul_div_expand_tensor = {
	(void*)batch_norm5_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm5_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm5_add_beta_expand_shape[3] = {32,1,1};
DLTensor batch_norm5_add_beta_expand_tensor = {
	(void*)batch_norm5_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm5_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 24 : relu5
// will not be used actually// float[1][32][56][56]
float* relu5 = nullptr;
const int64_t relu5_shape[4] = {1,32,56,56};
DLTensor relu5_tensor = {
	(void*)relu5/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu5_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv6_weight_shape[4] = {32,32,1,1};
DLTensor mobilenet0_conv6_weight_tensor = {
	(void*)mobilenet0_conv6_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv6_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm6_gamma_mul_div_expand_shape[3] = {32,1,1};
DLTensor batch_norm6_gamma_mul_div_expand_tensor = {
	(void*)batch_norm6_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm6_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm6_add_beta_expand_shape[3] = {32,1,1};
DLTensor batch_norm6_add_beta_expand_tensor = {
	(void*)batch_norm6_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm6_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 28 : relu6
// will not be used actually// float[1][32][56][56]
float* relu6 = nullptr;
const int64_t relu6_shape[4] = {1,32,56,56};
DLTensor relu6_tensor = {
	(void*)relu6/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu6_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv7_weight_shape[4] = {32,1,3,3};
DLTensor mobilenet0_conv7_weight_tensor = {
	(void*)mobilenet0_conv7_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv7_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm7_gamma_mul_div_expand_shape[3] = {32,1,1};
DLTensor batch_norm7_gamma_mul_div_expand_tensor = {
	(void*)batch_norm7_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm7_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm7_add_beta_expand_shape[3] = {32,1,1};
DLTensor batch_norm7_add_beta_expand_tensor = {
	(void*)batch_norm7_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm7_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 32 : relu7
// will not be used actually// float[1][32][28][28]
float* relu7 = nullptr;
const int64_t relu7_shape[4] = {1,32,28,28};
DLTensor relu7_tensor = {
	(void*)relu7/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu7_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv8_weight_shape[4] = {64,32,1,1};
DLTensor mobilenet0_conv8_weight_tensor = {
	(void*)mobilenet0_conv8_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv8_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm8_gamma_mul_div_expand_shape[3] = {64,1,1};
DLTensor batch_norm8_gamma_mul_div_expand_tensor = {
	(void*)batch_norm8_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm8_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm8_add_beta_expand_shape[3] = {64,1,1};
DLTensor batch_norm8_add_beta_expand_tensor = {
	(void*)batch_norm8_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm8_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 36 : relu8
// will not be used actually// float[1][64][28][28]
float* relu8 = nullptr;
const int64_t relu8_shape[4] = {1,64,28,28};
DLTensor relu8_tensor = {
	(void*)relu8/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu8_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv9_weight_shape[4] = {64,1,3,3};
DLTensor mobilenet0_conv9_weight_tensor = {
	(void*)mobilenet0_conv9_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv9_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm9_gamma_mul_div_expand_shape[3] = {64,1,1};
DLTensor batch_norm9_gamma_mul_div_expand_tensor = {
	(void*)batch_norm9_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm9_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm9_add_beta_expand_shape[3] = {64,1,1};
DLTensor batch_norm9_add_beta_expand_tensor = {
	(void*)batch_norm9_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm9_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 40 : relu9
// will not be used actually// float[1][64][28][28]
float* relu9 = nullptr;
const int64_t relu9_shape[4] = {1,64,28,28};
DLTensor relu9_tensor = {
	(void*)relu9/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu9_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv10_weight_shape[4] = {64,64,1,1};
DLTensor mobilenet0_conv10_weight_tensor = {
	(void*)mobilenet0_conv10_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv10_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm10_gamma_mul_div_expand_shape[3] = {64,1,1};
DLTensor batch_norm10_gamma_mul_div_expand_tensor = {
	(void*)batch_norm10_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm10_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm10_add_beta_expand_shape[3] = {64,1,1};
DLTensor batch_norm10_add_beta_expand_tensor = {
	(void*)batch_norm10_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm10_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 44 : relu10
// will not be used actually// float[1][64][28][28]
float* relu10 = nullptr;
const int64_t relu10_shape[4] = {1,64,28,28};
DLTensor relu10_tensor = {
	(void*)relu10/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu10_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv11_weight_shape[4] = {64,1,3,3};
DLTensor mobilenet0_conv11_weight_tensor = {
	(void*)mobilenet0_conv11_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv11_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm11_gamma_mul_div_expand_shape[3] = {64,1,1};
DLTensor batch_norm11_gamma_mul_div_expand_tensor = {
	(void*)batch_norm11_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm11_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm11_add_beta_expand_shape[3] = {64,1,1};
DLTensor batch_norm11_add_beta_expand_tensor = {
	(void*)batch_norm11_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm11_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 48 : relu11
// will not be used actually// float[1][64][14][14]
float* relu11 = nullptr;
const int64_t relu11_shape[4] = {1,64,14,14};
DLTensor relu11_tensor = {
	(void*)relu11/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu11_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv12_weight_shape[4] = {128,64,1,1};
DLTensor mobilenet0_conv12_weight_tensor = {
	(void*)mobilenet0_conv12_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv12_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm12_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm12_gamma_mul_div_expand_tensor = {
	(void*)batch_norm12_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm12_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm12_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm12_add_beta_expand_tensor = {
	(void*)batch_norm12_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm12_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 52 : relu12
// will not be used actually// float[1][128][14][14]
float* relu12 = nullptr;
const int64_t relu12_shape[4] = {1,128,14,14};
DLTensor relu12_tensor = {
	(void*)relu12/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu12_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv13_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv13_weight_tensor = {
	(void*)mobilenet0_conv13_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv13_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm13_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm13_gamma_mul_div_expand_tensor = {
	(void*)batch_norm13_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm13_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm13_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm13_add_beta_expand_tensor = {
	(void*)batch_norm13_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm13_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 56 : relu13
// will not be used actually// float[1][128][14][14]
float* relu13 = nullptr;
const int64_t relu13_shape[4] = {1,128,14,14};
DLTensor relu13_tensor = {
	(void*)relu13/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu13_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv14_weight_shape[4] = {128,128,1,1};
DLTensor mobilenet0_conv14_weight_tensor = {
	(void*)mobilenet0_conv14_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv14_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm14_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm14_gamma_mul_div_expand_tensor = {
	(void*)batch_norm14_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm14_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm14_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm14_add_beta_expand_tensor = {
	(void*)batch_norm14_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm14_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 60 : relu14
// will not be used actually// float[1][128][14][14]
float* relu14 = nullptr;
const int64_t relu14_shape[4] = {1,128,14,14};
DLTensor relu14_tensor = {
	(void*)relu14/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu14_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv15_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv15_weight_tensor = {
	(void*)mobilenet0_conv15_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv15_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm15_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm15_gamma_mul_div_expand_tensor = {
	(void*)batch_norm15_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm15_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm15_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm15_add_beta_expand_tensor = {
	(void*)batch_norm15_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm15_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 64 : relu15
// will not be used actually// float[1][128][14][14]
float* relu15 = nullptr;
const int64_t relu15_shape[4] = {1,128,14,14};
DLTensor relu15_tensor = {
	(void*)relu15/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu15_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv16_weight_shape[4] = {128,128,1,1};
DLTensor mobilenet0_conv16_weight_tensor = {
	(void*)mobilenet0_conv16_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv16_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm16_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm16_gamma_mul_div_expand_tensor = {
	(void*)batch_norm16_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm16_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm16_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm16_add_beta_expand_tensor = {
	(void*)batch_norm16_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm16_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 68 : relu16
// will not be used actually// float[1][128][14][14]
float* relu16 = nullptr;
const int64_t relu16_shape[4] = {1,128,14,14};
DLTensor relu16_tensor = {
	(void*)relu16/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu16_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv17_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv17_weight_tensor = {
	(void*)mobilenet0_conv17_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv17_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm17_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm17_gamma_mul_div_expand_tensor = {
	(void*)batch_norm17_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm17_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm17_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm17_add_beta_expand_tensor = {
	(void*)batch_norm17_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm17_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 72 : relu17
// will not be used actually// float[1][128][14][14]
float* relu17 = nullptr;
const int64_t relu17_shape[4] = {1,128,14,14};
DLTensor relu17_tensor = {
	(void*)relu17/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu17_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv18_weight_shape[4] = {128,128,1,1};
DLTensor mobilenet0_conv18_weight_tensor = {
	(void*)mobilenet0_conv18_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv18_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm18_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm18_gamma_mul_div_expand_tensor = {
	(void*)batch_norm18_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm18_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm18_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm18_add_beta_expand_tensor = {
	(void*)batch_norm18_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm18_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 76 : relu18
// will not be used actually// float[1][128][14][14]
float* relu18 = nullptr;
const int64_t relu18_shape[4] = {1,128,14,14};
DLTensor relu18_tensor = {
	(void*)relu18/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu18_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv19_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv19_weight_tensor = {
	(void*)mobilenet0_conv19_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv19_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm19_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm19_gamma_mul_div_expand_tensor = {
	(void*)batch_norm19_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm19_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm19_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm19_add_beta_expand_tensor = {
	(void*)batch_norm19_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm19_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 80 : relu19
// will not be used actually// float[1][128][14][14]
float* relu19 = nullptr;
const int64_t relu19_shape[4] = {1,128,14,14};
DLTensor relu19_tensor = {
	(void*)relu19/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu19_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv20_weight_shape[4] = {128,128,1,1};
DLTensor mobilenet0_conv20_weight_tensor = {
	(void*)mobilenet0_conv20_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv20_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm20_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm20_gamma_mul_div_expand_tensor = {
	(void*)batch_norm20_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm20_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm20_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm20_add_beta_expand_tensor = {
	(void*)batch_norm20_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm20_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 84 : relu20
// will not be used actually// float[1][128][14][14]
float* relu20 = nullptr;
const int64_t relu20_shape[4] = {1,128,14,14};
DLTensor relu20_tensor = {
	(void*)relu20/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu20_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv21_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv21_weight_tensor = {
	(void*)mobilenet0_conv21_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv21_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm21_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm21_gamma_mul_div_expand_tensor = {
	(void*)batch_norm21_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm21_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm21_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm21_add_beta_expand_tensor = {
	(void*)batch_norm21_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm21_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 88 : relu21
// will not be used actually// float[1][128][14][14]
float* relu21 = nullptr;
const int64_t relu21_shape[4] = {1,128,14,14};
DLTensor relu21_tensor = {
	(void*)relu21/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu21_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv22_weight_shape[4] = {128,128,1,1};
DLTensor mobilenet0_conv22_weight_tensor = {
	(void*)mobilenet0_conv22_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv22_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm22_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm22_gamma_mul_div_expand_tensor = {
	(void*)batch_norm22_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm22_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm22_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm22_add_beta_expand_tensor = {
	(void*)batch_norm22_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm22_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 92 : relu22
// will not be used actually// float[1][128][14][14]
float* relu22 = nullptr;
const int64_t relu22_shape[4] = {1,128,14,14};
DLTensor relu22_tensor = {
	(void*)relu22/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu22_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv23_weight_shape[4] = {128,1,3,3};
DLTensor mobilenet0_conv23_weight_tensor = {
	(void*)mobilenet0_conv23_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv23_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm23_gamma_mul_div_expand_shape[3] = {128,1,1};
DLTensor batch_norm23_gamma_mul_div_expand_tensor = {
	(void*)batch_norm23_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm23_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm23_add_beta_expand_shape[3] = {128,1,1};
DLTensor batch_norm23_add_beta_expand_tensor = {
	(void*)batch_norm23_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm23_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 96 : relu23
// will not be used actually// float[1][128][7][7]
float* relu23 = nullptr;
const int64_t relu23_shape[4] = {1,128,7,7};
DLTensor relu23_tensor = {
	(void*)relu23/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu23_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv24_weight_shape[4] = {256,128,1,1};
DLTensor mobilenet0_conv24_weight_tensor = {
	(void*)mobilenet0_conv24_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv24_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm24_gamma_mul_div_expand_shape[3] = {256,1,1};
DLTensor batch_norm24_gamma_mul_div_expand_tensor = {
	(void*)batch_norm24_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm24_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm24_add_beta_expand_shape[3] = {256,1,1};
DLTensor batch_norm24_add_beta_expand_tensor = {
	(void*)batch_norm24_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm24_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 100 : relu24
// will not be used actually// float[1][256][7][7]
float* relu24 = nullptr;
const int64_t relu24_shape[4] = {1,256,7,7};
DLTensor relu24_tensor = {
	(void*)relu24/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu24_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv25_weight_shape[4] = {256,1,3,3};
DLTensor mobilenet0_conv25_weight_tensor = {
	(void*)mobilenet0_conv25_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv25_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm25_gamma_mul_div_expand_shape[3] = {256,1,1};
DLTensor batch_norm25_gamma_mul_div_expand_tensor = {
	(void*)batch_norm25_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm25_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm25_add_beta_expand_shape[3] = {256,1,1};
DLTensor batch_norm25_add_beta_expand_tensor = {
	(void*)batch_norm25_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm25_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 104 : relu25
// will not be used actually// float[1][256][7][7]
float* relu25 = nullptr;
const int64_t relu25_shape[4] = {1,256,7,7};
DLTensor relu25_tensor = {
	(void*)relu25/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu25_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_conv26_weight_shape[4] = {256,256,1,1};
DLTensor mobilenet0_conv26_weight_tensor = {
	(void*)mobilenet0_conv26_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_conv26_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm26_gamma_mul_div_expand_shape[3] = {256,1,1};
DLTensor batch_norm26_gamma_mul_div_expand_tensor = {
	(void*)batch_norm26_gamma_mul_div_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm26_gamma_mul_div_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t batch_norm26_add_beta_expand_shape[3] = {256,1,1};
DLTensor batch_norm26_add_beta_expand_tensor = {
	(void*)batch_norm26_add_beta_expand/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	3/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)batch_norm26_add_beta_expand_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 108 : relu26
// will not be used actually// float[1][256][7][7]
float* relu26 = nullptr;
const int64_t relu26_shape[4] = {1,256,7,7};
DLTensor relu26_tensor = {
	(void*)relu26/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu26_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 109 : global_avg_pool2d0
// will not be used actually// float[1][256][1][1]
float* global_avg_pool2d0 = nullptr;
const int64_t global_avg_pool2d0_shape[4] = {1,256,1,1};
DLTensor global_avg_pool2d0_tensor = {
	(void*)global_avg_pool2d0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)global_avg_pool2d0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 110 : flatten0
// will not be used actually// float[1][256]
float* flatten0 = nullptr;
const int64_t flatten0_shape[2] = {1,256};
DLTensor flatten0_tensor = {
	(void*)flatten0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)flatten0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_dense0_weight_shape[2] = {1000,256};
DLTensor mobilenet0_dense0_weight_tensor = {
	(void*)mobilenet0_dense0_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_dense0_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t mobilenet0_dense0_bias_shape[1] = {1000};
DLTensor mobilenet0_dense0_bias_tensor = {
	(void*)mobilenet0_dense0_bias/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	1/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)mobilenet0_dense0_bias_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 113 : dense0
// will not be used actually// float[1][1000]
float* dense0 = nullptr;
const int64_t dense0_shape[2] = {1,1000};
DLTensor dense0_tensor = {
	(void*)dense0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)dense0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
TVMValue relu0_tvmval[5];
relu0_tvmval[0].v_handle = (void*)&data_tensor;
relu0_tvmval[1].v_handle = (void*)&mobilenet0_conv0_weight_tensor;
relu0_tvmval[2].v_handle = (void*)&batch_norm0_gamma_mul_div_expand_tensor;
relu0_tvmval[3].v_handle = (void*)&batch_norm0_add_beta_expand_tensor;
relu0_tvmval[4].v_handle = (void*)&relu0_tensor;
const int relu0_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu1_tvmval[5];
relu1_tvmval[0].v_handle = (void*)&relu0_tensor;
relu1_tvmval[1].v_handle = (void*)&mobilenet0_conv1_weight_tensor;
relu1_tvmval[2].v_handle = (void*)&batch_norm1_gamma_mul_div_expand_tensor;
relu1_tvmval[3].v_handle = (void*)&batch_norm1_add_beta_expand_tensor;
relu1_tvmval[4].v_handle = (void*)&relu1_tensor;
const int relu1_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu2_tvmval[5];
relu2_tvmval[0].v_handle = (void*)&relu1_tensor;
relu2_tvmval[1].v_handle = (void*)&mobilenet0_conv2_weight_tensor;
relu2_tvmval[2].v_handle = (void*)&batch_norm2_gamma_mul_div_expand_tensor;
relu2_tvmval[3].v_handle = (void*)&batch_norm2_add_beta_expand_tensor;
relu2_tvmval[4].v_handle = (void*)&relu2_tensor;
const int relu2_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu3_tvmval[5];
relu3_tvmval[0].v_handle = (void*)&relu2_tensor;
relu3_tvmval[1].v_handle = (void*)&mobilenet0_conv3_weight_tensor;
relu3_tvmval[2].v_handle = (void*)&batch_norm3_gamma_mul_div_expand_tensor;
relu3_tvmval[3].v_handle = (void*)&batch_norm3_add_beta_expand_tensor;
relu3_tvmval[4].v_handle = (void*)&relu3_tensor;
const int relu3_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu4_tvmval[5];
relu4_tvmval[0].v_handle = (void*)&relu3_tensor;
relu4_tvmval[1].v_handle = (void*)&mobilenet0_conv4_weight_tensor;
relu4_tvmval[2].v_handle = (void*)&batch_norm4_gamma_mul_div_expand_tensor;
relu4_tvmval[3].v_handle = (void*)&batch_norm4_add_beta_expand_tensor;
relu4_tvmval[4].v_handle = (void*)&relu4_tensor;
const int relu4_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu5_tvmval[5];
relu5_tvmval[0].v_handle = (void*)&relu4_tensor;
relu5_tvmval[1].v_handle = (void*)&mobilenet0_conv5_weight_tensor;
relu5_tvmval[2].v_handle = (void*)&batch_norm5_gamma_mul_div_expand_tensor;
relu5_tvmval[3].v_handle = (void*)&batch_norm5_add_beta_expand_tensor;
relu5_tvmval[4].v_handle = (void*)&relu5_tensor;
const int relu5_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu6_tvmval[5];
relu6_tvmval[0].v_handle = (void*)&relu5_tensor;
relu6_tvmval[1].v_handle = (void*)&mobilenet0_conv6_weight_tensor;
relu6_tvmval[2].v_handle = (void*)&batch_norm6_gamma_mul_div_expand_tensor;
relu6_tvmval[3].v_handle = (void*)&batch_norm6_add_beta_expand_tensor;
relu6_tvmval[4].v_handle = (void*)&relu6_tensor;
const int relu6_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu7_tvmval[5];
relu7_tvmval[0].v_handle = (void*)&relu6_tensor;
relu7_tvmval[1].v_handle = (void*)&mobilenet0_conv7_weight_tensor;
relu7_tvmval[2].v_handle = (void*)&batch_norm7_gamma_mul_div_expand_tensor;
relu7_tvmval[3].v_handle = (void*)&batch_norm7_add_beta_expand_tensor;
relu7_tvmval[4].v_handle = (void*)&relu7_tensor;
const int relu7_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu8_tvmval[5];
relu8_tvmval[0].v_handle = (void*)&relu7_tensor;
relu8_tvmval[1].v_handle = (void*)&mobilenet0_conv8_weight_tensor;
relu8_tvmval[2].v_handle = (void*)&batch_norm8_gamma_mul_div_expand_tensor;
relu8_tvmval[3].v_handle = (void*)&batch_norm8_add_beta_expand_tensor;
relu8_tvmval[4].v_handle = (void*)&relu8_tensor;
const int relu8_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu9_tvmval[5];
relu9_tvmval[0].v_handle = (void*)&relu8_tensor;
relu9_tvmval[1].v_handle = (void*)&mobilenet0_conv9_weight_tensor;
relu9_tvmval[2].v_handle = (void*)&batch_norm9_gamma_mul_div_expand_tensor;
relu9_tvmval[3].v_handle = (void*)&batch_norm9_add_beta_expand_tensor;
relu9_tvmval[4].v_handle = (void*)&relu9_tensor;
const int relu9_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu10_tvmval[5];
relu10_tvmval[0].v_handle = (void*)&relu9_tensor;
relu10_tvmval[1].v_handle = (void*)&mobilenet0_conv10_weight_tensor;
relu10_tvmval[2].v_handle = (void*)&batch_norm10_gamma_mul_div_expand_tensor;
relu10_tvmval[3].v_handle = (void*)&batch_norm10_add_beta_expand_tensor;
relu10_tvmval[4].v_handle = (void*)&relu10_tensor;
const int relu10_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu11_tvmval[5];
relu11_tvmval[0].v_handle = (void*)&relu10_tensor;
relu11_tvmval[1].v_handle = (void*)&mobilenet0_conv11_weight_tensor;
relu11_tvmval[2].v_handle = (void*)&batch_norm11_gamma_mul_div_expand_tensor;
relu11_tvmval[3].v_handle = (void*)&batch_norm11_add_beta_expand_tensor;
relu11_tvmval[4].v_handle = (void*)&relu11_tensor;
const int relu11_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu12_tvmval[5];
relu12_tvmval[0].v_handle = (void*)&relu11_tensor;
relu12_tvmval[1].v_handle = (void*)&mobilenet0_conv12_weight_tensor;
relu12_tvmval[2].v_handle = (void*)&batch_norm12_gamma_mul_div_expand_tensor;
relu12_tvmval[3].v_handle = (void*)&batch_norm12_add_beta_expand_tensor;
relu12_tvmval[4].v_handle = (void*)&relu12_tensor;
const int relu12_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu13_tvmval[5];
relu13_tvmval[0].v_handle = (void*)&relu12_tensor;
relu13_tvmval[1].v_handle = (void*)&mobilenet0_conv13_weight_tensor;
relu13_tvmval[2].v_handle = (void*)&batch_norm13_gamma_mul_div_expand_tensor;
relu13_tvmval[3].v_handle = (void*)&batch_norm13_add_beta_expand_tensor;
relu13_tvmval[4].v_handle = (void*)&relu13_tensor;
const int relu13_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu14_tvmval[5];
relu14_tvmval[0].v_handle = (void*)&relu13_tensor;
relu14_tvmval[1].v_handle = (void*)&mobilenet0_conv14_weight_tensor;
relu14_tvmval[2].v_handle = (void*)&batch_norm14_gamma_mul_div_expand_tensor;
relu14_tvmval[3].v_handle = (void*)&batch_norm14_add_beta_expand_tensor;
relu14_tvmval[4].v_handle = (void*)&relu14_tensor;
const int relu14_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu15_tvmval[5];
relu15_tvmval[0].v_handle = (void*)&relu14_tensor;
relu15_tvmval[1].v_handle = (void*)&mobilenet0_conv15_weight_tensor;
relu15_tvmval[2].v_handle = (void*)&batch_norm15_gamma_mul_div_expand_tensor;
relu15_tvmval[3].v_handle = (void*)&batch_norm15_add_beta_expand_tensor;
relu15_tvmval[4].v_handle = (void*)&relu15_tensor;
const int relu15_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu16_tvmval[5];
relu16_tvmval[0].v_handle = (void*)&relu15_tensor;
relu16_tvmval[1].v_handle = (void*)&mobilenet0_conv16_weight_tensor;
relu16_tvmval[2].v_handle = (void*)&batch_norm16_gamma_mul_div_expand_tensor;
relu16_tvmval[3].v_handle = (void*)&batch_norm16_add_beta_expand_tensor;
relu16_tvmval[4].v_handle = (void*)&relu16_tensor;
const int relu16_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu17_tvmval[5];
relu17_tvmval[0].v_handle = (void*)&relu16_tensor;
relu17_tvmval[1].v_handle = (void*)&mobilenet0_conv17_weight_tensor;
relu17_tvmval[2].v_handle = (void*)&batch_norm17_gamma_mul_div_expand_tensor;
relu17_tvmval[3].v_handle = (void*)&batch_norm17_add_beta_expand_tensor;
relu17_tvmval[4].v_handle = (void*)&relu17_tensor;
const int relu17_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu18_tvmval[5];
relu18_tvmval[0].v_handle = (void*)&relu17_tensor;
relu18_tvmval[1].v_handle = (void*)&mobilenet0_conv18_weight_tensor;
relu18_tvmval[2].v_handle = (void*)&batch_norm18_gamma_mul_div_expand_tensor;
relu18_tvmval[3].v_handle = (void*)&batch_norm18_add_beta_expand_tensor;
relu18_tvmval[4].v_handle = (void*)&relu18_tensor;
const int relu18_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu19_tvmval[5];
relu19_tvmval[0].v_handle = (void*)&relu18_tensor;
relu19_tvmval[1].v_handle = (void*)&mobilenet0_conv19_weight_tensor;
relu19_tvmval[2].v_handle = (void*)&batch_norm19_gamma_mul_div_expand_tensor;
relu19_tvmval[3].v_handle = (void*)&batch_norm19_add_beta_expand_tensor;
relu19_tvmval[4].v_handle = (void*)&relu19_tensor;
const int relu19_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu20_tvmval[5];
relu20_tvmval[0].v_handle = (void*)&relu19_tensor;
relu20_tvmval[1].v_handle = (void*)&mobilenet0_conv20_weight_tensor;
relu20_tvmval[2].v_handle = (void*)&batch_norm20_gamma_mul_div_expand_tensor;
relu20_tvmval[3].v_handle = (void*)&batch_norm20_add_beta_expand_tensor;
relu20_tvmval[4].v_handle = (void*)&relu20_tensor;
const int relu20_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu21_tvmval[5];
relu21_tvmval[0].v_handle = (void*)&relu20_tensor;
relu21_tvmval[1].v_handle = (void*)&mobilenet0_conv21_weight_tensor;
relu21_tvmval[2].v_handle = (void*)&batch_norm21_gamma_mul_div_expand_tensor;
relu21_tvmval[3].v_handle = (void*)&batch_norm21_add_beta_expand_tensor;
relu21_tvmval[4].v_handle = (void*)&relu21_tensor;
const int relu21_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu22_tvmval[5];
relu22_tvmval[0].v_handle = (void*)&relu21_tensor;
relu22_tvmval[1].v_handle = (void*)&mobilenet0_conv22_weight_tensor;
relu22_tvmval[2].v_handle = (void*)&batch_norm22_gamma_mul_div_expand_tensor;
relu22_tvmval[3].v_handle = (void*)&batch_norm22_add_beta_expand_tensor;
relu22_tvmval[4].v_handle = (void*)&relu22_tensor;
const int relu22_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu23_tvmval[5];
relu23_tvmval[0].v_handle = (void*)&relu22_tensor;
relu23_tvmval[1].v_handle = (void*)&mobilenet0_conv23_weight_tensor;
relu23_tvmval[2].v_handle = (void*)&batch_norm23_gamma_mul_div_expand_tensor;
relu23_tvmval[3].v_handle = (void*)&batch_norm23_add_beta_expand_tensor;
relu23_tvmval[4].v_handle = (void*)&relu23_tensor;
const int relu23_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu24_tvmval[5];
relu24_tvmval[0].v_handle = (void*)&relu23_tensor;
relu24_tvmval[1].v_handle = (void*)&mobilenet0_conv24_weight_tensor;
relu24_tvmval[2].v_handle = (void*)&batch_norm24_gamma_mul_div_expand_tensor;
relu24_tvmval[3].v_handle = (void*)&batch_norm24_add_beta_expand_tensor;
relu24_tvmval[4].v_handle = (void*)&relu24_tensor;
const int relu24_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu25_tvmval[5];
relu25_tvmval[0].v_handle = (void*)&relu24_tensor;
relu25_tvmval[1].v_handle = (void*)&mobilenet0_conv25_weight_tensor;
relu25_tvmval[2].v_handle = (void*)&batch_norm25_gamma_mul_div_expand_tensor;
relu25_tvmval[3].v_handle = (void*)&batch_norm25_add_beta_expand_tensor;
relu25_tvmval[4].v_handle = (void*)&relu25_tensor;
const int relu25_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu26_tvmval[5];
relu26_tvmval[0].v_handle = (void*)&relu25_tensor;
relu26_tvmval[1].v_handle = (void*)&mobilenet0_conv26_weight_tensor;
relu26_tvmval[2].v_handle = (void*)&batch_norm26_gamma_mul_div_expand_tensor;
relu26_tvmval[3].v_handle = (void*)&batch_norm26_add_beta_expand_tensor;
relu26_tvmval[4].v_handle = (void*)&relu26_tensor;
const int relu26_typeid[5] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue global_avg_pool2d0_tvmval[2];
global_avg_pool2d0_tvmval[0].v_handle = (void*)&relu26_tensor;
global_avg_pool2d0_tvmval[1].v_handle = (void*)&global_avg_pool2d0_tensor;
const int global_avg_pool2d0_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
TVMValue flatten0_tvmval[2];
flatten0_tvmval[0].v_handle = (void*)&global_avg_pool2d0_tensor;
flatten0_tvmval[1].v_handle = (void*)&flatten0_tensor;
const int flatten0_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
TVMValue dense0_tvmval[4];
dense0_tvmval[0].v_handle = (void*)&flatten0_tensor;
dense0_tvmval[1].v_handle = (void*)&mobilenet0_dense0_weight_tensor;
dense0_tvmval[2].v_handle = (void*)&mobilenet0_dense0_bias_tensor;
dense0_tvmval[3].v_handle = (void*)&dense0_tensor;
const int dense0_typeid[4] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
