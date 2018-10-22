#include "median.hpp"
#include "SimpleBus.h"
int sc_main(int argc, char **argv){
    Testbench test("test");
    Median median("median");
    SimpleBus<1,1> bus("bus");

    // Set TLM bus
    bus.set_clock_period(sc_time(CLOCK_PERIOD, SC_NS));
    test.initiator.i_skt(bus.t_skt[0]);
    bus.setDecode(0,SOBEL_MM_BASE,SOBEL_MM_BASE+SOBEL_MM_SIZE-1);
    bus.i_skt[0](median.t_skt);
    // do median filter
    test.read_bmp();
    median.set_h_w(test.get_height(), test.get_width());
    sc_start();
    test.write_bmp();
    
    return 0;
}
