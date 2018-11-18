const int64_t data_shape[4] = {1,3,16,16};
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
// will not be used actually// float[1][8][8][8]
float* relu0 = nullptr;
const int64_t relu0_shape[4] = {1,8,8,8};
DLTensor relu0_tensor = {
	(void*)relu0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu0_shape /*shape*/, 
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
