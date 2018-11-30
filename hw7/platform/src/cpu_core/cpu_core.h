#pragma once

#include "ovpworld.org/modelSupport/tlmPlatform/1.0/tlm2.0/tlmPlatform.hpp"
#include "riscv.ovpworld.org/processor/riscv/1.0/tlm2.0/processor.igen.hpp"
#include "ovpworld.org/modelSupport/tlmDecoder/1.0/tlm2.0/tlmDecoder.hpp"
#include "ovpworld.org/memory/ram/1.0/tlm2.0/tlmMemory.hpp"

#include "common/memory_map.h"
#include "scml_bridge.h"

class CpuCore : public sc_module{
public:
	CpuCore(const sc_module_name &name);
	~CpuCore() {}

	/* Port list */
	scml2::initiator_socket<32> &i_socket;

	/* Components inside CPU core */
	icmTLMPlatform platform;
	riscv risc_v;
	decoder<2, 3> tile_bus;
	ram program_ram;
	ram stack_ram;
	ScmlBridge bus_bridge;

private:
	icmAttrListObject* attrsForCpu() {
		icmAttrListObject* userAttrs = new icmAttrListObject;
		userAttrs->addAttr("variant", "RV32I");
		return userAttrs;
	}
};
