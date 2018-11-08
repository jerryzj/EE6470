#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif

#include "filter_def.h"

class Testbench : public sc_module {
public:
    // Clock, reset signal
    sc_in_clk i_clk;
    sc_out < bool >  o_rst;

#ifndef NATIVE_SYSTEMC
    cynw_p2p< sc_dt::sc_uint<32> >::base_out output;
    cynw_p2p< sc_dt::sc_uint<32> >::base_in input;
#else
    sc_fifo_out< sc_dt::sc_uint<32> > output;
    sc_fifo_in< sc_dt::sc_uint<32> > input;
#endif

    SC_HAS_PROCESS(Testbench);

    Testbench(sc_module_name n);
    ~Testbench();

private:
    void GenTestData();
    void fetch_result();

    sc_uint<32> tensor[i_ch * i_width * i_height];
    sc_uint<32> result;

    unsigned int n_txn;
    sc_time max_txn_time;
    sc_time min_txn_time;
    sc_time total_txn_time;
    sc_time total_start_time;
    sc_time total_run_time;
};
#endif
