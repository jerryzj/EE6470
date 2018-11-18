#include "testbench.h"

#include <iomanip>

#include "common/memory_map.h"
#include "BaremetalDNN_main.cpp"

Testbench::Testbench(const sc_module_name &name) :
	sc_module(name),
	i_socket("i_socket")
{
	SC_THREAD(Test_Thread);
}

void Testbench::Test_Thread() {
	BaremetalDNN_model_wraper();
}

void Testbench::LoadTestData(uint address, float* data, uint data_num) {
	i_socket.write_debug<unsigned int>(address, reinterpret_cast<unsigned int*>(data), data_num);
}

void Testbench::GetResult(uint address, float* data, uint data_num) {
	i_socket.read_debug<unsigned int>(address, reinterpret_cast<unsigned int*>(data), data_num);
}

void Testbench::ConfigConvDMA(vector<DmaChConfig> &config) {
	/* Check if DMA is idle */
	uint status;
	do {
		wait(AccessTime(sizeof(uint) * 1), SC_NS);
		i_socket.read<uint>(POOL_DMA_BASE_ADDRESS + (0 << 2), status);
	} while(status != 0);

	/* Program config registers */
	for(uint i = 0; i < config.size(); i++) {
		if(config[i].channel_enable == 1) {
			wait(AccessTime(sizeof(uint) * 7), SC_NS);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 1) << 2), config[i].source_address);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 2) << 2), config[i].dest_address);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 3) << 2), config[i].transfer_length);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 4) << 2), config[i].transfer_type);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 5) << 2), config[i].line_length);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 6) << 2), config[i].line_stride);
			i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + ((16 * (i + 1) + 0) << 2), config[i].channel_enable);
		}
	}

	/* Start DMA for service */
	wait(AccessTime(sizeof(uint) * 1), SC_NS);
	i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + (1 << 2), 1);

	/* Wait DMA until it is done (idle) */
	do {
		wait(AccessTime(sizeof(uint) * 1), SC_NS);
		i_socket.read<uint>(POOL_DMA_BASE_ADDRESS + (0 << 2), status);
	} while(status != 0);

	/* Stop DMA for service */
	wait(AccessTime(sizeof(uint) * 1), SC_NS);
	i_socket.write<uint>(POOL_DMA_BASE_ADDRESS + (1 << 2), 0);
}

void Testbench::ConfigConvEngine(ConvConfig &config) {
	/* Check if pooling engine is ready (idle) for configuring */
	uint status;
	do {
		wait(AccessTime(sizeof(uint) * 1), SC_NS);
		i_socket.read<uint>(POOL_BASE_ADDRESS + (0 << 2), status);
	} while(status != 0);

	/* Program config registers */
	wait(AccessTime(sizeof(uint) * 12), SC_NS);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (2 << 2), config.kernel_addr);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (3 << 2), config.data_in_address);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (4 << 2), config.data_out_address);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (5 << 2), config.data_cube_in_width);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (6 << 2), config.data_cube_in_height);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (7 << 2), config.data_cube_in_channel);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (8 << 2), config.data_cube_out_width);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (9 << 2), config.data_cube_out_height);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (10 << 2), config.data_cube_out_channel);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (11 << 2), config.filter_width);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (12 << 2), config.filter_stride);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (13 << 2), config.zero_padding);

	/* Set OPEnable */
	wait(AccessTime(sizeof(uint) * 1), SC_NS);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (1 << 2), 1);

	/* Wait Pool engine until it is done */
	do {
		wait(AccessTime(sizeof(uint) * 1), SC_NS);
		i_socket.read<uint>(POOL_BASE_ADDRESS + (0 << 2), status);
	} while(status != 0);
}

void Testbench::PrintData(float* data, uint channel, uint height, uint width) {
	for(uint i = 0; i < channel; i++) {
		cout << "Channel #" << i << '\n';
		for(uint j = 0; j < height; j++) {
			for(uint k = 0; k < width; k++) {
				uint index(i * height * width + j * width + k);
				cout << std::fixed << std::setw(8) << std::setprecision(2) << data[index];
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << endl;
}

uint Testbench::AccessTime(float data_length_in_bytes) {
	return ceil(data_length_in_bytes / BUS_WIDTH);
}
