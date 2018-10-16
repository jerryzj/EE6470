#include "median.hpp"

int sc_main(int argc, char **argv){
    Testbench test("test");
    Median median("median");

    test.initiator.i_skt(median.t_skt);
    test.read_bmp();
    median.set_h_w(test.get_height(), test.get_width());
    sc_start();
    test.write_bmp();
    
    return 0;
}
