#include <cmath>
#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "Pooling.h"

Pooling::Pooling( sc_module_name n ): sc_module( n ){
#ifndef NATIVE_SYSTEMC
    HLS_FLATTEN_ARRAY(val);
#endif
    SC_THREAD( do_pooling );
    sensitive << i_clk.pos();
    dont_initialize();
    reset_signal_is(i_rst, false);
#ifndef NATIVE_SYSTEMC
    input.clk_rst(i_clk, i_rst);
    output.clk_rst(i_clk, i_rst);
#endif
}

Pooling::~Pooling() {}

void Pooling::do_pooling() {
    {
#ifndef NATIVE_SYSTEMC
        HLS_DEFINE_PROTOCOL("main_reset");
        input.reset();
        output.reset();
#endif
        wait();
    }
    while (true) {
        for (unsigned int i = 0; i < 4; ++i) {
            HLS_CONSTRAIN_LATENCY(0, 1, "lat00");
            val[i] = 0;
        }
        for (unsigned int v = 0; v< 4; ++v) {
#ifndef NATIVE_SYSTEMC
                {
                    HLS_DEFINE_PROTOCOL("input");
                    val[v] = input.get();
                    wait();
                }
#else
                val[v]= input.read();
#endif
        }
        sc_uint<32> result = 0;
        for (unsigned int i = 0; i < 4; ++i) {
            HLS_CONSTRAIN_LATENCY(0, 1, "lat01");
            if(val[i] > result){
                result = val[i];
            }
        }
#ifndef NATIVE_SYSTEMC
        {
            HLS_DEFINE_PROTOCOL("output");
            output.put(result);
            wait();
        }
#else
        o_result.write(total);
#endif
    }
}
