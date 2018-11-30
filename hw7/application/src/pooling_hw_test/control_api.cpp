#include "control_api.h"

#include <cstring>

#include "common/memory_map.h"

void control_api::ConfigPoolEngine(const PoolConfig &config) {
	/* Check if pooling engine is ready (idle) for configuring */
	while(read_reg(POOL_BASE_ADDRESS + (0 << 2)) != 0) {}

	/* Program config registers */
	write_reg(POOL_BASE_ADDRESS + (2 << 2), config.pool_function);
	write_reg(POOL_BASE_ADDRESS + (3 << 2), config.data_in_address);
	write_reg(POOL_BASE_ADDRESS + (4 << 2), config.data_out_address);
	write_reg(POOL_BASE_ADDRESS + (5 << 2), config.data_cube_in_width);
	write_reg(POOL_BASE_ADDRESS + (6 << 2), config.data_cube_in_height);
	write_reg(POOL_BASE_ADDRESS + (7 << 2), config.data_cube_in_channel);
	write_reg(POOL_BASE_ADDRESS + (8 << 2), config.data_cube_out_width);
	write_reg(POOL_BASE_ADDRESS + (9 << 2), config.data_cube_out_height);
	write_reg(POOL_BASE_ADDRESS + (10 << 2), config.data_cube_out_channel);
	write_reg(POOL_BASE_ADDRESS + (11 << 2), config.filter_width);
	write_reg(POOL_BASE_ADDRESS + (12 << 2), config.filter_stride);
	write_reg(POOL_BASE_ADDRESS + (13 << 2), config.zero_padding);

	/* Set OPEnable */
	write_reg(POOL_BASE_ADDRESS + (1 << 2), 1);

	/* Wait Pool engine until it is done */
	while(read_reg(POOL_BASE_ADDRESS + (0 << 2)) != 0) {}
}

void control_api::ConfigPoolDMA(const vector<DmaChConfig> &config) {
	/* Check if DMA is idle */
	while(read_reg(POOL_DMA_BASE_ADDRESS + (0 << 2)) != 0) {}

	/* Program config registers */
	for(uint i = 0; i < config.size(); i++) {
		if(config[i].channel_enable == 1) {
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 1) << 2), config[i].source_address);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 2) << 2), config[i].dest_address);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 3) << 2), config[i].transfer_length);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 4) << 2), config[i].transfer_type);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 5) << 2), config[i].line_length);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 6) << 2), config[i].line_stride);
			write_reg(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 0) << 2), config[i].channel_enable);
		}
	}

	/* Start DMA for service */
	write_reg(POOL_DMA_BASE_ADDRESS + (1 << 2), 1);

	/* Wait DMA until it is done (idle) */
	while(read_reg(POOL_DMA_BASE_ADDRESS + (0 << 2)) != 0) {}

	/* Stop DMA for service */
	write_reg(POOL_DMA_BASE_ADDRESS + (1 << 2), 0);
}

void control_api::write_reg(const uint address, const uint data) {
	*reinterpret_cast<volatile uint*>(address) = data;
}

uint control_api::read_reg(const uint address) {
	uint data = *reinterpret_cast<volatile uint*>(address);

	return data;
}

template <typename T>
void control_api::write_data(const uint address, T* const data, const uint data_num) {
	memcpy(reinterpret_cast<void*>(address),
	       reinterpret_cast<unsigned char*>(data),
	       data_num * sizeof(T));
}
template void control_api::write_data<int>(const uint, int* const, const uint);
template void control_api::write_data<short>(const uint, short* const, const uint);
template void control_api::write_data<float>(const uint, float* const, const uint);

template <typename T>
void control_api::read_data(const uint address, T* const data, const uint data_num) {
	memcpy(reinterpret_cast<unsigned char*>(data),
	       reinterpret_cast<void*>(address),
	       data_num * sizeof(T));
}
template void control_api::read_data<int>(const uint, int* const, const uint);
template void control_api::read_data<short>(const uint, short* const, const uint);
template void control_api::read_data<float>(const uint, float* const, const uint);
