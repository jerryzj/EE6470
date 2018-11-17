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
        read_in_part_sum();
        read_data();    // load data to local buffer
        for(uint h = 0; h < o_height; ++h){
        for(uint w = 0; w < o_width; ++w){
            result = 0;
            for(uint rh = 0; rh < k_height; ++rh){
            for(uint rw = 0; rw < k_width; ++rw){
                result += ip_sum[h][w] + tensor[stride*h+rh][sitride*w+rw] * kernel[rh][rw];
            }}
#ifndef NATIVE_SYSTEMC
{
                HLS_DEFINE_PROTOCOL("output");
                output.put(result);
}
#else
                output.write(result);
#endif
        }}
    }
}

void Pooling::read_kernel(){
    for(uint k = 0; k < k_width; ++k){
    for(uint l = 0; l < K_height; ++l){
#ifndef NATIVE_SYSTEMC
{
        HLS_DEFINE_PROTOCOL("input");
        kernel[k][l] = input.get();
}
#else
        kernel[k][l] = input.read();
#endif
    }}
}

void Pooling::read_data()
    for(uint j = 0; j < i_width; ++j){
    for(uint k = 0; k < i_height; ++k){
#ifndef NATIVE_SYSTEMC
{
        HLS_DEFINE_PROTOCOL("input");
        tensor[j][k] = input.get();
}
#else
        tensor[j][k] = input.read();
#endif
    }}
}

void Pooling::read_in_part_sum(){
    for(uint i = 0; i < o_width; ++i){
    for(uint j = 0; j < o_height; ++j){
#ifndef NATIVE_SYSTEMC
{
        HLS_DEFINE_PROTOCOL("input");
        ip_sum[i][j] = input.get();
}
#else
        ip_sum[i][j] = input.read();
#endif
    }}
}
