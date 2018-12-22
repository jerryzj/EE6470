#pragma once

#include "pool_engine/pool_engine.h"
#include "memory/memory_model.h"
#include "dma/dma.h"

class AccPlatform : public sc_module {
public:
	AccPlatform(const sc_module_name &name);
	~AccPlatform() {}

	/* Port list */
	tlm::tlm_target_socket<32> bus_t_socket_0;

private:
	/* Interconnect */
	scml2::router<uint> bus;

	/* Accelerator */
	PoolEngine pool_engine;

	/* DMA */
	DMA pool_dma;

	/* Memory */
	MemoryModel<unsigned char> global_buffer;

	/* Port list */
	tlm::tlm_target_socket<32> bus_t_socket_1;

	/* Port adaptor list */
	scml2::tlm2_gp_target_adapter<32> bus_t_adapter_0;
	scml2::tlm2_gp_target_adapter<32> bus_t_adapter_1;
};
