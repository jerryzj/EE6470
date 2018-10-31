#include "testbench.h"

#include <iomanip>

#include "common/memory_map.h"

Testbench::Testbench(const sc_module_name &name) :
	sc_module(name),
	i_socket("i_socket")
{
	SC_THREAD(Test_Thread);
}

void Testbench::Test_Thread() {
	PoolConfig pool_config;
	ePoolFunction function(is_maximum);
	pool_config.pool_function         = static_cast<uint>(function);
	pool_config.data_cube_in_width    = 5;
	pool_config.data_cube_in_height   = pool_config.data_cube_in_width;
	pool_config.data_cube_in_channel  = 2;
	pool_config.filter_width          = 3;
	pool_config.filter_stride         = 1;
	pool_config.zero_padding          = 0;
	pool_config.data_cube_out_width  = ((pool_config.data_cube_in_height + 2 * pool_config.zero_padding)
	                                   - pool_config.filter_width) / pool_config.filter_stride + 1;
	pool_config.data_cube_out_height  = pool_config.data_cube_out_width;
	pool_config.data_cube_out_channel = pool_config.data_cube_in_channel;
	pool_config.data_in_address       = POOL_BUFFER_ADDRESS;
	pool_config.data_out_address      = POOL_BUFFER_ADDRESS
	                                    + (pool_config.data_cube_in_channel
	                                       * pool_config.data_cube_in_height
	                                       * pool_config.data_cube_in_width
	                                      ) * sizeof(float);

	cout << "[Test information]\n"
	     << "        Pooling function: ";
	switch(function) {
		case is_maximum: cout << "maximum"; break;
		case is_average: cout << "average"; break;
		case is_minimum: cout << "minimum"; break;
		default: assert(0 && "This pooling function hasn't been supported yet.");
	}
	cout << '\n'
	     << "               Data type: floating point 32\n"
	     << "    Input data dimension: " << pool_config.data_cube_in_channel
	                                     << " x " << pool_config.data_cube_in_height 
	                                     << " x " << pool_config.data_cube_in_width << '\n'
	     << "            Zero Padding: " << pool_config.zero_padding << '\n'	     
	     << "     Pooling window size: " << pool_config.filter_width
	                                     << " x " << pool_config.filter_width << '\n'
	     << "   Pooling window stride: " << pool_config.filter_stride << '\n'
	     << "   Output data dimension: " << pool_config.data_cube_out_channel
	                                     << " x " << pool_config.data_cube_out_height
	                                     << " x " << pool_config.data_cube_out_width << '\n' << endl;

	uint test_data_num(pool_config.data_cube_in_channel
	                   * pool_config.data_cube_in_height
	                   * pool_config.data_cube_in_width);

	uint result_num(pool_config.data_cube_out_channel
	                * pool_config.data_cube_out_height
	                * pool_config.data_cube_out_width);

	/* Generate random test data then load them into RAM through debug transport (no timing effort) */
	float* test_data = new float[test_data_num];
	GenTestData(test_data, test_data_num);

	cout << "Test data cube:\n";
	PrintData(test_data,
	          pool_config.data_cube_in_channel,
	          pool_config.data_cube_in_height,
	          pool_config.data_cube_in_width);

	LoadTestData(GLOBAL_BUFFER_ADDRESS, test_data, test_data_num);

	/* Configure DMA to load test data into buffer from RAM */
	vector<DmaChConfig> dma_config(1);
	dma_config[0].channel_enable  = 1;
	dma_config[0].source_address  = GLOBAL_BUFFER_ADDRESS;
	dma_config[0].dest_address    = pool_config.data_in_address;
	dma_config[0].transfer_length = test_data_num * sizeof(float);
	dma_config[0].transfer_type   = 3;
	dma_config[0].line_length     = 0;
	dma_config[0].line_stride     = 0;
	ConfigPoolDMA(dma_config);

	/* Configure pooling engine to process test data */
	ConfigPoolEngine(pool_config);

	/* Configure DMA to move results from buffer into RAM */
	dma_config[0].channel_enable  = 1;
	dma_config[0].source_address  = pool_config.data_out_address;
	dma_config[0].dest_address    = GLOBAL_BUFFER_ADDRESS;
	dma_config[0].transfer_length = result_num * sizeof(float);
	dma_config[0].transfer_type   = 3;
	dma_config[0].line_length     = 0;
	dma_config[0].line_stride     = 0;
	ConfigPoolDMA(dma_config);

	/* Get result from RAM through debug transport (no timing effort) */
	float* result = new float[result_num];
	GetResult(GLOBAL_BUFFER_ADDRESS, result, result_num);

	cout << "Result cube:\n";
	PrintData(result,
	          pool_config.data_cube_out_channel,
	          pool_config.data_cube_out_height,
	          pool_config.data_cube_out_width);
	
	if(test_data) delete[] test_data;
	if(result) delete[] result;
}

void Testbench::GenTestData(float* data, uint data_num) {
	for(uint i = 0; i < data_num; i++)
		data[i] = rand() % 256;
}

void Testbench::LoadTestData(uint address, float* data, uint data_num) {
	i_socket.write_debug<unsigned int>(address, reinterpret_cast<unsigned int*>(data), data_num);
}

void Testbench::GetResult(uint address, float* data, uint data_num) {
	i_socket.read_debug<unsigned int>(address, reinterpret_cast<unsigned int*>(data), data_num);
}

void Testbench::ConfigPoolDMA(vector<DmaChConfig> &config) {
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

void Testbench::ConfigPoolEngine(PoolConfig &config) {
	/* Check if pooling engine is ready (idle) for configuring */
	uint status;
	do {
		wait(AccessTime(sizeof(uint) * 1), SC_NS);
		i_socket.read<uint>(POOL_BASE_ADDRESS + (0 << 2), status);
	} while(status != 0);

	/* Program config registers */
	wait(AccessTime(sizeof(uint) * 12), SC_NS);
	i_socket.write<uint>(POOL_BASE_ADDRESS + (2 << 2), config.pool_function);
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
