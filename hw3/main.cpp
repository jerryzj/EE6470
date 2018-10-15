#include "median.hpp"

int sc_main(int argc, char **argv){
    Testbench test("test");
    Median median("median");

    test.initiator.i_skt(median.t_skt);
    test.read_bmp();
    sc_start();
    test.write_bmp();
    
    return 0;
}
