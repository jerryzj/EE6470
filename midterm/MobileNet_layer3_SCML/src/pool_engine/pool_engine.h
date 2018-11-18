#pragma once

#include <scml2.h>

class PoolEngine : public sc_module {
public:
	SC_HAS_PROCESS(PoolEngine);

	PoolEngine(const sc_module_name &name);
	~PoolEngine() {}

	/* Methods */
	void PrintConfigReg() const;

	/* Port list */
	tlm::tlm_target_socket<32> t_socket;

	/* Config registers */
	scml2::memory<uint> config_reg;

	/* Local buffer */
	scml2::memory<unsigned char> data_buffer;

private:
	/* Main Thread */
	void PoolEngineThread();

	/* Write callback methods for event driven config register */
	bool WriteOPEnable(const uint &enable);

	/* Methods */
	void DoPooling();

	/* Config register aliases */
	scml2::reg<uint> status;
	scml2::reg<uint> op_enable;
	scml2::reg<uint> pool_function;
	scml2::reg<uint> data_in_address;
	scml2::reg<uint> data_out_address;
	scml2::reg<uint> data_cube_in_width;
	scml2::reg<uint> data_cube_in_height;
	scml2::reg<uint> data_cube_in_channel;
	scml2::reg<uint> data_cube_out_widhth;
	scml2::reg<uint> data_cube_out_height;
	scml2::reg<uint> data_cube_out_channel;
	scml2::reg<uint> filter_width;
	scml2::reg<uint> filter_stride;
	scml2::reg<uint> zero_padding;

	/* Port adaptor list */
	scml2::tlm2_gp_target_adapter<32> t_adapter;

	sc_event event_reg_op_enable;

	sc_time pool_period;
};
