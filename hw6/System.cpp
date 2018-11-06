#include "System.h"
System::System( sc_module_name n, string input_bmp, string output_bmp ): sc_module( n ), 
    tb("tb"), Pooling("pooling"), clk("clk", CLOCK_PERIOD, SC_NS), rst("rst"){
    tb.i_clk(clk);
    tb.o_rst(rst);
    pooling.i_clk(clk);
    pooling.i_rst(rst);
    tb.o_rgb(rgb);
    tb.i_result(result);
    pooling.input(input);
    pooling.output(output);
}

System::~System() {}
