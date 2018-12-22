#pragma once

#include "ovpworld.org/modelSupport/tlmPlatform/1.0/tlm2.0/tlmPlatform.hpp"

#include "acc_platform/common/memory_map.h"
#include "cpu_core/cpu_core.h"
#include "scml_bridge/scml_bridge.h"

template <unsigned int NUM_CORE>
class MultiCpuCore : public sc_module {
public:
	MultiCpuCore(const sc_module_name &name)
		: sc_module(name),
		  platform("platform", ICM_VERBOSE | ICM_STOP_ON_CTRLC | ICM_ENABLE_IMPERAS_INTERCEPTS),
		  system_bus("system_bus"),
		  shared_memory("shared_memory", "t_socket", SHARED_MEMORY_SIZE - 1),
		  bus_bridge("bus_bridge", ACC_START_ADDRESS),
		  i_socket(bus_bridge.i_socket)
	{
		/* New CPU cores */
		InitCores();

		/* Connect CPU cores and system bus */
		ConnectCores();

		/* Connect shared memory and system bus */
		system_bus.initiator_socket[0](shared_memory.sp1);
		system_bus.setDecode(0, SHARED_MEMORY_ADDRESS, SHARED_MEMORY_ADDRESS + SHARED_MEMORY_SIZE - 1);

		/* Connect bus bridge and system bus */
		system_bus.initiator_socket[1](bus_bridge.t_socket);
		system_bus.setDecode(1, ACC_START_ADDRESS, ACC_END_ADDRESS);
	}

	~MultiCpuCore() {
		for(unsigned int n = 0; n < NUM_CORE; n++)
			delete cpu[n];
	}

	/* Port list */
	scml2::initiator_socket<32> &i_socket;

	/* OVP platform */
	icmTLMPlatform platform;
	
	/* CPU cores */
	CpuCore* cpu[NUM_CORE];

	/* Bus */
	decoder<NUM_CORE, 2> system_bus;

	/* Memory */
	ram shared_memory;

	/* Bus bridge */
	ScmlBridge bus_bridge;

	/* Load parallel program */
	void LoadProgram(const char *app_name) {
		for(unsigned int n = 0; n < NUM_CORE; n++)
			cpu[n]->risc_v.loadLocalMemory(app_name, (icmLoaderAttrs)(ICM_LOAD_VERBOSE | ICM_SET_START));
	}

	void assert_reset() {
		for(unsigned int n = 0; n < NUM_CORE; n++)
			cpu[n]->reset.write(1);
	}

	void deassert_reset() {
		for(unsigned int n = 0; n < NUM_CORE; n++)
			cpu[n]->reset.write(0);
	}

private:
	void InitCores() {
		for(unsigned int n = 0; n < NUM_CORE; n++)
			cpu[n] = new CpuCore(GenName("cpu_", n).c_str(), n);
	}

	void ConnectCores() {
		for(unsigned int n = 0; n < NUM_CORE; n ++) {
			cpu[n]->tile_bus.initiator_socket[1](system_bus.target_socket[n]);
			cpu[n]->tile_bus.setDecode(1, SHARED_MEMORY_ADDRESS, ACC_END_ADDRESS);
		}
	}
};
