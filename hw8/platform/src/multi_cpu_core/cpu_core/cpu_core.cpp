#include "cpu_core.h"

#include "acc_platform/common/memory_map.h"

string GenName(const string prefix, const unsigned int ID) {
	return (prefix + to_string(ID));
}

CpuCore::CpuCore(const sc_module_name &name, const unsigned int ID)
	: sc_module(name),
	  risc_v(GenName("riscv_", ID).c_str(), ID, ICM_ATTR_DEFAULT_SEMIHOST, attrsForCpu(), NULL, 32, true, 0, 1000),
	  tile_bus(GenName("tile_bus_", ID).c_str()),
	  stack_ram(GenName("stack_ram_", ID).c_str(), "t_socket", STACK_RAM_SIZE - 1)
{
	/* Connect CPU and tile bus */
	risc_v.INSTRUCTION.socket(tile_bus.target_socket[0]);
	risc_v.DATA.socket(tile_bus.target_socket[1]);

	/* Connect stack memory and tile bus */
	tile_bus.initiator_socket[0](stack_ram.sp1);
	tile_bus.setDecode(0, STACK_RAM_END_ADDRESS - STACK_RAM_SIZE + 1, STACK_RAM_END_ADDRESS);
}

icmAttrListObject* CpuCore::attrsForCpu() {
	icmAttrListObject* userAttrs = new icmAttrListObject;
	userAttrs->addAttr("variant", "RV32IMAC");
	return userAttrs;
}
