#include <iostream>
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include "sync.h"
#include "OpUtil.h"

PoolConfig pool_config;
float input_f[4* 12* 12];
float output_f[4*6*6];
int core_num;             // Number of core

void BaremetalDNN_model_wraper();

extern "C" void thread_entry(int cid, int nc) {

	core_num = nc;

	if(cid == 0){// Run the whole network on core 0
		BaremetalDNN_model_wraper();
	}
	else{
		for(int run = 0; run < 2; run++){
			std::cout<<"Core: "<<gethartid()<<std::endl;
			barrier(core_num);
			// Real compuatations, divide computation by channel
			int ch_start = (pool_config.out_ch / core_num) * gethartid();
			int ch_end;
			if(gethartid() == core_num - 1){
				ch_end = pool_config.out_ch;
			}
			else{
				ch_end = (pool_config.out_ch / core_num) * (gethartid()+ 1);
			}
			for(unsigned int c = ch_start; c < ch_end; ++c) {
			for(unsigned int h = 0; h < pool_config.out_h; ++h) {
			for(unsigned int w = 0; w < pool_config.out_w; ++w) {
    			//const auto Oidx = output_shape.Idx(c,h,w);
    			const auto Oidx = c * pool_config.out_h * pool_config.out_w
    		                	+ h * pool_config.out_w
    		                	+ w;
    			// initialize with minimum value
    			auto max = -FLT_MAX;
    			for(unsigned int fh = 0; fh < pool_config.stride; ++fh) {
    			for(unsigned int fw = 0; fw < pool_config.stride; ++fw) {
    				const auto Ih = (h * pool_config.stride) + fh;
    				const auto Iw = (w * pool_config.stride) + fw;
    				const auto Iidx = c * pool_config.in_h * pool_config.in_w
    		                    	+ h * pool_config.in_w
    		                    	+ w;
    				max = fmax(max, input_f[Iidx]);
    			}}
    			output_f[Oidx] = max;
  			}}}
			std::cout<<"Finish Pooling in Core"<<gethartid()<<std::endl;
			barrier(core_num);
		}
	}
}