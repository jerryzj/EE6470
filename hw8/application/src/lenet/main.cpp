#include <iostream>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include "sync.h"
#include "control_api.h"

PoolConfig pool_config;   // Pooling configuration
float* input_f, output_f; // Input/Output feature
int core_num;             // Number of core

void BaremetalDNN_model_wraper();

extern "C" void thread_entry(int cid, int nc) {

	core_num = nc;

	if(cid == 0){// Run the whole network on core 0
		BaremetalDNN_model_wraper();
	}
	else{
		// Real compuatations, divide computation by channel
		int ch_start = (pool_config.data_cube_out_channel / core_num) * gethartid();
		int ch_end;
		if(gethartid() == core_num - 1){
			ch_end = pool_config.data_cube_out_channel;
		}
		else{
			ch_end = (pool_config.data_cube_out_channel / core_num) * (gethartid()+ 1);
		}
		for(unsigned int c = ch_start; c < ch_end; ++c) {
		for(unsigned int h = 0; h < pool_config.data_cube_out_height; ++h) {
		for(unsigned int w = 0; w < pool_config.data_cube_out_width; ++w) {
    		//const auto Oidx = output_shape.Idx(c,h,w);
    		const auto Oidx = c * pool_config.data_cube_out_height * pool_config.data_cube_out_width
    		                + h * pool_config.data_cube_out_width
    		                + w;
    		// initialize with minimum value
    		auto max = -FLT_MAX;
    		for(unsigned int fh = 0; fh < pool_config.filter_stride; ++fh) {
    		for(unsigned int fw = 0; fw < pool_config.filter_stride; ++fw) {
    			const auto Ih = (h * pool_config.filter_stride) + fh;
    			const auto Iw = (w * pool_config.filter_stride) + fw;
    			const auto Iidx = c * pool_config.data_cube_in_height * pool_config.data_cube_in_width
    		                    + h * pool_config.data_cube_in_width
    		                    + w;
    			max = fmax(max, input_f[Iidx]);
    		}}
    		output_f[Oidx] = max;
  		}}}
	}
}