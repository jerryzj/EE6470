#include "acc_platform/acc_platform.h"
#include "multi_cpu_core/multi_cpu_core.h"

int sc_main(int argc, char** argv) {
	const char *app_name;
	if (argc == 2) {
		app_name = argv[1];
	} else {
		cout << "Usage: $ your_platform.plat your_application.app\n"
		     << "Please specify application" << endl;
		assert(0);
	}

	const unsigned int num_core = 4;
	MultiCpuCore<num_core> multi_cpu_core("multi_cpu_core");
	AccPlatform acc_platform("acc_platform");

	multi_cpu_core.i_socket(acc_platform.bus_t_socket_0);

	multi_cpu_core.LoadProgram(app_name);

	sc_start();
	std::cout<< "Simulated time:" << sc_core::sc_time_stamp() << std::endl;

	return 0;
}
