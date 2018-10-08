#include "median.hpp"

int sc_main(int argc, char **argv){
    Testbench test("test");
    Median median("median");
    sc_fifo<int> r,g,b;
    sc_fifo<int> update_index;
    sc_fifo<int> filter_r,filter_g,filter_b;

    // Input Stage Connection
    test.o_update_index(update_index);
    median.i_update_index(update_index);
    test.o_red(filter_r);
    median.i_red(filter_r);
    test.o_green(filter_g);
    median.i_green(filter_g);
    test.o_blue(filter_b);
    median.i_blue(filter_b);
    // Output Stage Connection
    median.o_red(r);
    test.i_red(r);
    median.o_green(g);
    test.i_green(g);
    median.o_blue(b);
    test.i_blue(b);
    cout<<"Connection Established"<<endl;
    sc_start();
    return 0;
}
