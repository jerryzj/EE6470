#include <iostream>
#include <iomanip>
#include <cassert>
#include <limits>

using uint = unsigned int;
using namespace std;

enum ePoolFunction {is_maximum = 0, is_average = 1, is_minimum = 2};

typedef struct {
	ePoolFunction pool_function;
	float* data_in_ptr;
	float* data_out_ptr;
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

void GenTestData(float* const data, const uint data_num);
void PrintData(const float* const data, const uint channel, const uint height, const uint width);
void DoPooling(const PoolConfig &pool_config);

int main(int argc, char *argv[]) {
	cout << "###########################\n"
	     << "# Entering RISC-V process #\n"
	     << "###########################\n" << endl;

	PoolConfig pool_config;
	pool_config.pool_function         = is_maximum;
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

	cout << "[Test information]\n"
	     << "        Pooling function: ";
	switch(pool_config.pool_function) {
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
	float* test_data = new float[test_data_num];

	uint result_num(pool_config.data_cube_out_channel
	                * pool_config.data_cube_out_height
	                * pool_config.data_cube_out_width);
	float* result = new float[result_num];

	pool_config.data_in_ptr  = test_data;
	pool_config.data_out_ptr = result;

	/* Generate random test data */
	GenTestData(test_data, test_data_num);

	cout << "Test data cube:" << endl;
	PrintData(test_data,
	          pool_config.data_cube_in_channel,
	          pool_config.data_cube_in_height,
	          pool_config.data_cube_in_width);

	/* Do pooling function */
	DoPooling(pool_config);

	/* Print results */
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

void DoPooling(const PoolConfig &pool_config) {
	for(uint out_ch_idx = 0; out_ch_idx < pool_config.data_cube_out_channel; out_ch_idx++) {
		for(uint out_h_idx = 0; out_h_idx < pool_config.data_cube_out_height; out_h_idx++) {
			for(uint out_w_idx = 0; out_w_idx < pool_config.data_cube_out_width; out_w_idx++) {
				/* Pooling window coverage on input data plane */
				int win_h_start(out_h_idx * pool_config.filter_stride - pool_config.zero_padding);
				int win_w_start(out_w_idx * pool_config.filter_stride - pool_config.zero_padding);
				int win_h_end  (win_h_start + pool_config.filter_width);
				int win_w_end  (win_w_start + pool_config.filter_width);

				float temp_data;
				switch(pool_config.pool_function) {
				case is_maximum:
					temp_data = std::numeric_limits<float>::lowest();
				case is_average:
					temp_data = 0;
					break;
				case is_minimum:
					temp_data = std::numeric_limits<float>::max();
					break;
				default: assert(0 && "Pooling Engine hasn't support this function yet.");
				}

				for(int in_h_idx = win_h_start; in_h_idx < win_h_end; in_h_idx++) {
					for(int in_w_idx = win_w_start; in_w_idx < win_w_end; in_w_idx++) {
						if((in_h_idx < 0) || (in_h_idx >= pool_config.data_cube_in_height)
							|| (in_w_idx < 0) || (in_w_idx >= pool_config.data_cube_in_width)) {
							switch(pool_config.pool_function) {
							case is_maximum:
								if(0 > temp_data) temp_data = 0.0;
								break;
							case is_average:
								break;
							case is_minimum:
								if(0 < temp_data) temp_data = 0.0;
								break;
							default: assert(0 && "Pooling Engine hasn't support this function yet.");
							}
						} else {
							int data_in_idx(out_ch_idx * pool_config.data_cube_in_height * pool_config.data_cube_in_width
							                + in_h_idx * pool_config.data_cube_in_width + in_w_idx);
							float mem_r_data(pool_config.data_in_ptr[data_in_idx]);

							switch(pool_config.pool_function) {
							case is_maximum:
								if(mem_r_data > temp_data) temp_data = mem_r_data;
								break;
							case is_average:
								temp_data += mem_r_data;
								break;
							case is_minimum:
								if(mem_r_data < temp_data) temp_data = mem_r_data;
								break;
							default: assert(0 && "Pooling Engine hasn't support this function yet.");
							}
						}
					}
				}

				uint window_size(pool_config.filter_width * pool_config.filter_width);
				switch(pool_config.pool_function) {
				case is_maximum:
				case is_minimum:
					break;
				case is_average:
					temp_data = temp_data / window_size;
					break;
				default: assert(0 && "Pooling Engine hasn't support this function yet.");
				}

				int data_out_idx(out_ch_idx * pool_config.data_cube_out_height * pool_config.data_cube_out_width
				                 + out_h_idx * pool_config.data_cube_out_width + out_w_idx);
				pool_config.data_out_ptr[data_out_idx] = temp_data;
			}
		}
	}
}
