#pragma once

#include <vector>

using uint = unsigned int;
using namespace std;

typedef struct {
	uint pool_function;
	uint data_in_address;
	uint data_out_address;
	uint data_cube_in_width;
	uint data_cube_in_height;
	uint data_cube_in_channel;
	uint data_cube_out_width;
	uint data_cube_out_height;
	uint data_cube_out_channel;
	uint filter_width;
	uint filter_stride;
	uint zero_padding;
} PoolConfig;

typedef struct {
	uint channel_enable;
	uint source_address;
	uint dest_address;
	uint transfer_length;
	uint transfer_type;
	uint line_length;
	uint line_stride;
} DmaChConfig;

class control_api {
public:
	control_api() {}
	~control_api() {}

	/* Engine/DMA configuration methods */
	void ConfigPoolEngine(const PoolConfig &config);
	void ConfigPoolDMA(const vector<DmaChConfig> &config);

	/* Register access methods */
	void write_reg(const uint address, const uint data);
	uint read_reg(const uint address);

	/* Data access methods */
	template <typename T> void write_data(const uint address, T* const data, const uint data_num);
	template <typename T> void read_data(const uint address, T* const data, const uint data_num);
};
