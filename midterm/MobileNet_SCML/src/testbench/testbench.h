#pragma once

#include <scml2.h>

using namespace std;

typedef struct {
	uint kernel_addr; // 11/18 revised: Add convolution kernel input address
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
} ConvConfig;

typedef struct {
	uint channel_enable;
	uint source_address;
	uint dest_address;
	uint transfer_length;
	uint transfer_type;
	uint line_length;
	uint line_stride;
} DmaChConfig;

class Testbench : public sc_module {
public:
	scml2::initiator_socket<32> i_socket;

	SC_HAS_PROCESS(Testbench);

	Testbench(const sc_module_name &name);
	~Testbench() {}
	void LoadTestData(uint address, float* data, uint data_num);
	void GetResult(uint address, float* data, uint data_num);
	void ConfigPoolDMA(vector<DmaChConfig> &config);
	void ConfigPoolEngine(ConvConfig &config);
	void PrintData(float* data, uint channel, uint height, uint width);

private:
	/* Main thread */
	void Test_Thread();
	/* Bus timing model */
	uint AccessTime(float data_length_in_bytes);
};