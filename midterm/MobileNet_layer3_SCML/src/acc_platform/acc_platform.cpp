#include "acc_platform.h"

#include "common/memory_map.h"

AccPlatform::AccPlatform(const sc_module_name &name)
	: sc_module(name),
	  bus_t_socket_0("bus_t_socket_0"),
	  bus_t_socket_1("bus_t_socket_1"),
	  bus("bus", 0x100000000 / sizeof(uint)),
	  conv_engine("conv_engine"),
	  conv_dma("conv_dma", is_engine_type, POOL_BUFFER_ADDRESS, POOL_BUFFER_ADDRESS + POOL_BUFFER_SIZE - 1),
	  global_buffer("global_buffer", GLOBAL_BUFFER_SIZE),
	  bus_t_adapter_0("bus_t_adapter_0", bus_t_socket_0),
	  bus_t_adapter_1("bus_t_adapter_1", bus_t_socket_1)
{
	/* For debug only */
	if(!bus.map(POOL_BUFFER_ADDRESS, POOL_BUFFER_SIZE, conv_engine.data_buffer, 0))
		assert(0 && "Error in binding bus with accelerator buffer for debugging");
	/* End */

	if(!bus.map(POOL_DMA_BASE_ADDRESS, (1 + DMA_CHANNEL_NUM) * 16 * sizeof(uint), conv_dma.config_reg, 0))
		assert(0 && "Error in binding bus with DMA registers");

	if(!bus.map(POOL_BASE_ADDRESS, POOL_REG_NUM * sizeof(uint), conv_engine.config_reg, 0))
		assert(0 && "Error in binding bus with accelerator registers");

	if(!bus.map(GLOBAL_BUFFER_ADDRESS, GLOBAL_BUFFER_SIZE, global_buffer.memory_bank, 0))
		assert(0 && "Error in binding bus with memory");

	bus_t_adapter_0(bus);
	bus_t_adapter_1(bus);

	conv_dma.global_i_socket(bus_t_socket_1);
	conv_dma.local_i_socket(conv_engine.t_socket);
}

void AccPlatform::memory_load( const unsigned int begin, unsigned int size, const char* const file_name ) {
	global_buffer.memory_load(begin, size, file_name);
}

void AccPlatform::memory_dump( const unsigned int begin, unsigned int size, const char* const file_name ) {
	global_buffer.memory_dump(begin, size, file_name);
}
