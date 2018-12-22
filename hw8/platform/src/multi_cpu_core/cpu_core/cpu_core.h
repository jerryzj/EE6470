#pragma once

#include "riscv.ovpworld.org/processor/riscv/1.0/tlm2.0/processor.igen.hpp"
#include "ovpworld.org/modelSupport/tlmDecoder/1.0/tlm2.0/tlmDecoder.hpp"
#include "ovpworld.org/memory/ram/1.0/tlm2.0/tlmMemory.hpp"

string GenName(const string prefix, const unsigned int ID);

class CpuCore : public sc_module{
public:
	CpuCore(const sc_module_name &name,
	        const unsigned int ID);
	~CpuCore() {}

	/* Components inside CPU core */
	riscv risc_v;
	decoder<2, 2> tile_bus;
	ram stack_ram;

private:
	icmAttrListObject* attrsForCpu();
};
