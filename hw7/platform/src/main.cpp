#include "cpu_core/cpu_core.h"
#include "acc_platform/acc_platform.h"

int sc_main(int argc, char** argv) {
	sc_set_time_resolution(1, SC_NS);

	CpuCore cpu("cpu");
	AccPlatform acc_platform("acc_platform");
	cpu.i_socket(acc_platform.bus_t_socket_0);

	const char *app_name;
	if (argc == 2) {
		app_name = argv[1];
	} else {
		cout << "Usage: $ your_platform.plat your_application.app\n"
		     << "Please specify application" << endl;
		assert(0);
	}
	cpu.risc_v.loadLocalMemory(app_name, (icmLoaderAttrs)(ICM_LOAD_VERBOSE | ICM_SET_START));

	sc_start();
	std::cout<< "Simulated time:" << sc_core::sc_time_stamp() << std::endl;

	return 0;
}
