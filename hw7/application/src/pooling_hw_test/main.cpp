#include <iostream>
#include <iomanip>
#include <cassert>

#include "control_api.h"
#include "common/memory_map.h"

void GenTestData(float* const data, const uint data_num);
void PrintData(const float* const data, const uint channel, const uint height, const uint width);

int main(int argc, char *argv[]) {
	cout << "###########################\n"
	     << "# Entering RISC-V process #\n"
	     << "###########################\n" << endl;

	control_api ctrl_api;

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

	cout << "Test data cube:" << endl;
	PrintData(test_data,
	          pool_config.data_cube_in_channel,
	          pool_config.data_cube_in_height,
	          pool_config.data_cube_in_width);

	ctrl_api.write_data<float>(GLOBAL_BUFFER_ADDRESS, test_data, test_data_num);

	/* Configure DMA to load test data into buffer from RAM */
	vector<DmaChConfig> dma_config(1);
	dma_config[0].channel_enable  = 1;
	dma_config[0].source_address  = GLOBAL_BUFFER_ADDRESS;
	dma_config[0].dest_address    = pool_config.data_in_address;
	dma_config[0].transfer_length = test_data_num * sizeof(float);
	dma_config[0].transfer_type   = 3;
	dma_config[0].line_length     = 0;
	dma_config[0].line_stride     = 0;
	ctrl_api.ConfigPoolDMA(dma_config);

	/* Configure pooling engine to process test data */
	ctrl_api.ConfigPoolEngine(pool_config);

	/* Configure DMA to move results from buffer into RAM */
	dma_config[0].channel_enable  = 1;
	dma_config[0].source_address  = pool_config.data_out_address;
	dma_config[0].dest_address    = GLOBAL_BUFFER_ADDRESS;
	dma_config[0].transfer_length = result_num * sizeof(float);
	dma_config[0].transfer_type   = 3;
	dma_config[0].line_length     = 0;
	dma_config[0].line_stride     = 0;
	ctrl_api.ConfigPoolDMA(dma_config);

	/* Get result from RAM through debug transport (no timing effort) */
	float* result = new float[result_num];
	ctrl_api.read_data<float>(GLOBAL_BUFFER_ADDRESS, result, result_num);

	cout << "Result cube:" << endl;
	PrintData(result,
	          pool_config.data_cube_out_channel,
	          pool_config.data_cube_out_height,
	          pool_config.data_cube_out_width);
	
	if(test_data) delete[] test_data;
	if(result) delete[] result;

	cout << "\n##########################\n"
	     << "# Leaving RISC-V process #\n"
	     << "##########################" << endl;
	return 0;
}

void GenTestData(float* const data, const uint data_num) {
	for(uint i = 0; i < data_num; i++)
		data[i] = rand() % 256;
}

void PrintData(const float* const data, const uint channel, const uint height, const uint width) {
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
