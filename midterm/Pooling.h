#ifndef POOLING_H_
#define POOLING_H_
#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif

#include <cmath>
#include "filter_def.h"

class Pooling: public sc_module{
public:
    sc_in_clk i_clk;
    sc_in <bool>  i_rst;
#ifndef NATIVE_SYSTEMC
    cynw_p2p< sc_dt::sc_uint<32> >::in input;
    cynw_p2p< sc_dt::sc_uint<32> >::out output;
#else
    sc_fifo_in< sc_dt::sc_uint<32> > input;
    sc_fifo_out< sc_dt::sc_uint<32> > output;
#endif
    SC_HAS_PROCESS( Pooling );
    Pooling( sc_module_name n );
    ~Pooling();
private:
    void do_pooling();
    void read_kernel();
    void read_data();

    sc_uint<32> result;
    sc_uint<32> tensor [i_ch][i_width][i_height];
    sc_uint<32> kernel [k_batch_sizee][k_ch][k_width][k_height];
    sc_uint<32> unit[stride* stride];
};
#endif
