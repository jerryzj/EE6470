#include "acc_platform.h"

AccPlatform::AccPlatform(const sc_module_name &name)
	: sc_module(name),
	  bus_t_socket_0("bus_t_socket_0"),
	  bus_t_socket_1("bus_t_socket_1"),
	  bus("bus", 0x100000000 / sizeof(uint)),
	  pool_engine("pool_engine"),
	  pool_dma("pool_dma", is_engine_type, POOL_BUFFER_ADDRESS, POOL_BUFFER_ADDRESS + POOL_BUFFER_SIZE - 1),
	  global_buffer("global_buffer", GLOBAL_BUFFER_SIZE),
	  bus_t_adapter_0("bus_t_adapter_0", bus_t_socket_0),
	  bus_t_adapter_1("bus_t_adapter_1", bus_t_socket_1)
{
	/* For debug only */
	if(!bus.map(POOL_BUFFER_ADDRESS, POOL_BUFFER_SIZE, pool_engine.data_buffer, 0))
		assert(0 && "Error in binding bus with accelerator buffer for debugging");
	/* End */

	if(!bus.map(POOL_DMA_BASE_ADDRESS, (1 + DMA_CHANNEL_NUM) * 16 * sizeof(uint), pool_dma.config_reg, 0))
		assert(0 && "Error in binding bus with DMA registers");

	if(!bus.map(POOL_BASE_ADDRESS, POOL_REG_NUM * sizeof(uint), pool_engine.config_reg, 0))
		assert(0 && "Error in binding bus with accelerator registers");

	if(!bus.map(GLOBAL_BUFFER_ADDRESS, GLOBAL_BUFFER_SIZE, global_buffer.memory_bank, 0))
		assert(0 && "Error in binding bus with memory");

	bus_t_adapter_0(bus);
	bus_t_adapter_1(bus);

	pool_dma.global_i_socket(bus_t_socket_1);
	pool_dma.local_i_socket(pool_engine.t_socket);
}
