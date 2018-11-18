#pragma once

#include "conv_engine/conv_engine.h"
#include "memory/memory_model.h"
#include "dma/dma.h"

class AccPlatform : public sc_module {
public:
	AccPlatform(const sc_module_name &name);
	~AccPlatform() {}

	/* Port list */
	tlm::tlm_target_socket<32> bus_t_socket_0;

	/* Memory land & dump */
	void memory_load( const unsigned int begin, unsigned int size, const char* const file_name );
	void memory_dump( const unsigned int begin, unsigned int size, const char* const file_name );

private:
	/* Interconnect */
	scml2::router<uint> bus;

	/* Accelerator */
	ConvEngine conv_engine;

	/* DMA */
	DMA conv_dma;

	/* Memory */
	MemoryModel<unsigned char> global_buffer;

	/* Port list */
	tlm::tlm_target_socket<32> bus_t_socket_1;

	/* Port adaptor list */
	scml2::tlm2_gp_target_adapter<32> bus_t_adapter_0;
	scml2::tlm2_gp_target_adapter<32> bus_t_adapter_1;
};
