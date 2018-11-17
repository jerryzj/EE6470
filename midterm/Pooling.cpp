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
        read_kernel();
        read_data();    // load data to local buffer
        for(int c = 0; c < i_ch; ++c){
        //HLS_CONSTRAIN_LATENCY(0, 1, "pooling_latency");
        for(int w = 0; w < i_width; w+=stride){
        for(int h = 0; h < i_height; h+=stride){
            result = 0;
            unit[0] = tensor[c][w][h];
            unit[1] = tensor[c][w][h+1];
            unit[2] = tensor[c][w+1][h];
            unit[3] = tensor[c][w+1][h+1];
            for(int i = 0; i < stride * stride; i++){
                if(result < unit[i]){
                    result = unit[i];
                }
            }
#ifndef NATIVE_SYSTEMC
{
                HLS_DEFINE_PROTOCOL("output");
                output.put(result);
                //wait();
}
#else
                output.write(result);
#endif
        }}}
    }
}

void Pooling::read_kernel(){
    for(int i = 0; i < k_batch_size; ++i){
    for(int j = 0; j < k_ch; ++j){
    for(int k = 0; k < k_width; ++k){
    for(int l = 0; l < K_height; ++l){
#ifndef NATIVE_SYSTEMC
{
        HLS_DEFINE_PROTOCOL("input");
        kernel[i][j][k][l] = input.get();
        wait();
}
#else
        kernel[i][j][k][l] = input.read();
#endif
    }}}}
}

void Pooling::read_data(){
    for(int i = 0; i < i_ch; ++i){
    for(int j = 0; j < i_width; ++j){
    for(int k = 0; k < i_height; ++k){
#ifndef NATIVE_SYSTEMC
{
        HLS_DEFINE_PROTOCOL("input");
        tensor[i][j][k] = input.get();
        wait();
}
#else
        tensor[i][j][k] = input.read();
#endif
    }}}
}
