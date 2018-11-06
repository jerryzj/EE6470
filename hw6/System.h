#ifndef SYSTEM_H_
#define SYSTEM_H_
#include <systemc>
using namespace sc_core;

#include "Testbench.h"
#ifndef NATIVE_SYSTEMC
#include "Pooling_wrap.h"
#else
#include "Pooling.h"
#endif

class System: public sc_module{
public:
    SC_HAS_PROCESS( System );
    System( sc_module_name n, std::string input_bmp, std::string output_bmp );
    ~System();
private:
    Testbench tb;
#ifndef NATIVE_SYSTEMC
    Pooling_wrapper pooling;
#else
    Pooling pooling;
#endif
    sc_clock clk;
    sc_signal<bool> rst;
#ifndef NATIVE_SYSTEMC
    cynw_p2p< sc_dt::sc_uint<32> > input;
    cynw_p2p< sc_dt::sc_uint<32> > output;
#else
    sc_fifo< sc_dt::sc_uint<32> > input;
    sc_fifo< sc_dt::sc_uint<32> > output;
#endif
    std::string _output_bmp;
};
#endif
