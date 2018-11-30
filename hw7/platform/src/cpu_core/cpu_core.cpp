#include "cpu_core.h"

CpuCore::CpuCore(const sc_module_name &name)
	: sc_module(name),
	  platform("platform", ICM_VERBOSE | ICM_STOP_ON_CTRLC | ICM_ENABLE_IMPERAS_INTERCEPTS),
	  risc_v("RISC-V", 0, ICM_ATTR_DEFAULT_SEMIHOST, attrsForCpu(), NULL, 32, true, 0, 1000),
	  tile_bus("tile_bus"),
	  program_ram("program_ram", "t_socket", PROGRAM_RAM_SIZE - 1),
	  stack_ram("stack_ram", "t_socket", STACK_RAM_SIZE - 1),
	  bus_bridge("bus_bridge", ACC_START_ADDRESS),
	  i_socket(bus_bridge.i_socket)
{
	/* Set platform quantum for synchronizing global time */
	platform.quantum(sc_time(1, SC_NS));

	/* Connect CPU and tile bus */
	risc_v.INSTRUCTION.socket(tile_bus.target_socket[0]);
	risc_v.DATA.socket(tile_bus.target_socket[1]);

	/* Connect program memory and tile bus */
	tile_bus.initiator_socket[0](program_ram.sp1);
	tile_bus.setDecode(0, PROGRAM_RAM_ADDRESS, PROGRAM_RAM_ADDRESS + PROGRAM_RAM_SIZE - 1);

	/* Connect stack memory and tile bus */
	tile_bus.initiator_socket[1](stack_ram.sp1);
	tile_bus.setDecode(1, STACK_RAM_END_ADDRESS - STACK_RAM_SIZE + 1, STACK_RAM_END_ADDRESS);

	/* Connect bus bridge and tile bus */
	tile_bus.initiator_socket[2](bus_bridge.t_socket);
	tile_bus.setDecode(2, ACC_START_ADDRESS, ACC_END_ADDRESS);
}
