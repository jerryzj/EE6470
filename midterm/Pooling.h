#ifndef POOLING_H_
#define POOLING_H_
#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif

#include <cmath>
#include "filter_def.h"

using sc_uint<8> uint;

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
    void read_in_part_sum();

    sc_uint<32> result;
    sc_uint<32> tensor [i_width][i_height];
    sc_uint<32> kernel [k_width][k_height];
    sc_uint<32> ip_sum [o_width][o_height];
};
#endif
