#include "testbench/testbench.h"
#include "acc_platform/acc_platform.h"

int sc_main(int argc, char** argv) {
	Testbench testbench("testbench");
	AccPlatform acc_platform("acc_platform");
	testbench.i_socket(acc_platform.bus_t_socket_0);

	sc_start();
	std::cout<< "Simulated time:" << sc_core::sc_time_stamp() << std::endl;

	return 0;
}
