#include "median.hpp"
#include "memory_map.h"
#include "SimpleBus.h"
int sc_main(int argc, char **argv){
    Testbench test("test");
    Median median("median");
    SimpleBus<1,1> bus("bus");

    // Set TLM bus
    bus.set_clock_period(sc_time(CLOCK_PERIOD, SC_NS));
    bus.setDecode(0,SOBEL_MM_BASE,SOBEL_MM_BASE+SOBEL_MM_SIZE-1);
    bus.i_skt[0](median.t_skt);
    test.initiator.i_skt(bus.t_skt[0]);
    // do median filter
    test.read_bmp();
    median.set_h_w(test.get_height(), test.get_width());
    sc_start();
    test.write_bmp();
    
    return 0;
}
