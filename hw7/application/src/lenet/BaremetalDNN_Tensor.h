const int32_t data_shape[4] = {1,1,14,14};
DLTensor data_tensor = {
	(void*)data/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)data_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_conv0_weight_shape[4] = {4,1,3,3};
DLTensor net0_conv0_weight_tensor = {
	(void*)net0_conv0_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_conv0_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_conv0_bias_shape[1] = {4};
DLTensor net0_conv0_bias_tensor = {
	(void*)net0_conv0_bias/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	1/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_conv0_bias_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 3 : relu0
// will not be used actually// float[1][4][12][12]
float* relu0 = nullptr;
const int32_t relu0_shape[4] = {1,4,12,12};
DLTensor relu0_tensor = {
	(void*)relu0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)relu0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 4 : max_pool2d0
// will not be used actually// float[1][4][6][6]
float* max_pool2d0 = nullptr;
const int32_t max_pool2d0_shape[4] = {1,4,6,6};
DLTensor max_pool2d0_tensor = {
	(void*)max_pool2d0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)max_pool2d0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_conv1_weight_shape[4] = {8,4,3,3};
DLTensor net0_conv1_weight_tensor = {
	(void*)net0_conv1_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_conv1_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_conv1_bias_shape[1] = {8};
DLTensor net0_conv1_bias_tensor = {
	(void*)net0_conv1_bias/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	1/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_conv1_bias_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 7 : relu1
// will not be used actually// float[1][8][4][4]
float* relu1 = nullptr;
const int32_t relu1_shape[4] = {1,8,4,4};
DLTensor relu1_tensor = {
	(void*)relu1/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)relu1_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 8 : max_pool2d1
// will not be used actually// float[1][8][2][2]
float* max_pool2d1 = nullptr;
const int32_t max_pool2d1_shape[4] = {1,8,2,2};
DLTensor max_pool2d1_tensor = {
	(void*)max_pool2d1/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)max_pool2d1_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 9 : flatten0
// will not be used actually// float[1][32]
float* flatten0 = nullptr;
const int32_t flatten0_shape[2] = {1,32};
DLTensor flatten0_tensor = {
	(void*)flatten0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)flatten0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_dense0_weight_shape[2] = {10,32};
DLTensor net0_dense0_weight_tensor = {
	(void*)net0_dense0_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_dense0_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int32_t net0_dense0_bias_shape[1] = {10};
DLTensor net0_dense0_bias_tensor = {
	(void*)net0_dense0_bias/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	1/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)net0_dense0_bias_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 12 : dense0
// will not be used actually// float[1][10]
float* dense0 = nullptr;
const int32_t dense0_shape[2] = {1,10};
DLTensor dense0_tensor = {
	(void*)dense0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	2/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int32_t*)dense0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
TVMValue relu0_tvmval[4];
relu0_tvmval[0].v_handle = (void*)&data_tensor;
relu0_tvmval[1].v_handle = (void*)&net0_conv0_weight_tensor;
relu0_tvmval[2].v_handle = (void*)&net0_conv0_bias_tensor;
relu0_tvmval[3].v_handle = (void*)&relu0_tensor;
const int relu0_typeid[4] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue max_pool2d0_tvmval[2];
max_pool2d0_tvmval[0].v_handle = (void*)&relu0_tensor;
max_pool2d0_tvmval[1].v_handle = (void*)&max_pool2d0_tensor;
const int max_pool2d0_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
TVMValue relu1_tvmval[4];
relu1_tvmval[0].v_handle = (void*)&max_pool2d0_tensor;
relu1_tvmval[1].v_handle = (void*)&net0_conv1_weight_tensor;
relu1_tvmval[2].v_handle = (void*)&net0_conv1_bias_tensor;
relu1_tvmval[3].v_handle = (void*)&relu1_tensor;
const int relu1_typeid[4] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue max_pool2d1_tvmval[2];
max_pool2d1_tvmval[0].v_handle = (void*)&relu1_tensor;
max_pool2d1_tvmval[1].v_handle = (void*)&max_pool2d1_tensor;
const int max_pool2d1_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
TVMValue flatten0_tvmval[2];
flatten0_tvmval[0].v_handle = (void*)&max_pool2d1_tensor;
flatten0_tvmval[1].v_handle = (void*)&flatten0_tensor;
const int flatten0_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
TVMValue dense0_tvmval[4];
dense0_tvmval[0].v_handle = (void*)&flatten0_tensor;
dense0_tvmval[1].v_handle = (void*)&net0_dense0_weight_tensor;
dense0_tvmval[2].v_handle = (void*)&net0_dense0_bias_tensor;
dense0_tvmval[3].v_handle = (void*)&dense0_tensor;
const int dense0_typeid[4] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
