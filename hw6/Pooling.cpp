#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "Pooling.h"

Pooling::Pooling( sc_module_name n ): sc_module( n ){
#ifndef NATIVE_SYSTEMC
    HLS_FLATTEN_ARRAY(tensor);
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
    while(true){
        result = 0;
        read_data();    // load data to local buffer
        for(int c = 0; c < i_ch; ++c){
        for(int h = 0; h < i_height; ++h){
        for(int w = 0; w < i_width; ++w){
            for(int x = 0; x < window_h; ++x){
            for(int y = 0; y < window_w; ++y){
                win_h_start = (h * stride) + y;
                win_w_start = (w * stride) + x;
                offset = c * o_ch + win_w_start * o_width + win_h_start * o_height;
                if(result < tensor[offset]){
                    result = tensor[offset];
                }
            }}
#ifndef NATIVE_SYSTEMC
{
                HLS_DEFINE_PROTOCOL("output");
                output.put(result);
                wait();
}
#else
                output.write(result);
#endif
        }}}
    }
}

void Pooling::read_data(){
    sc_dt::sc_uint<32> offset = 0;
    for(int i = 0; i < i_ch; ++i){
    for(int j = 0; j < i_width; ++j){
    for(int k = 0; k < i_height; ++k){
        offset = i * i_ch + j * i_width + k * i_height;
#ifndef NATIVE_SYSTEMC
{
        HLS_CONSTRAIN_LATENCY(0, 2, "pooling_read_latency");
        HLS_DEFINE_PROTOCOL("input");
        tensor[offset] = input.get();
        wait();
}
#else
        tensor[offset] = input.read();
#endif
    }}}
}
