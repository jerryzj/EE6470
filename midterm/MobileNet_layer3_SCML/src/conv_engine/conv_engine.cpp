#include "conv_engine.h"

#include <limits>

#include "common/memory_map.h"

ConvEngine::ConvEngine(const sc_module_name &name)
	: sc_module(name),
	  t_socket("t_socket"),
	  t_adapter("t_adapter", t_socket),
	  pool_period(CLOCK_PERIOD, SC_NS),
	  config_reg("config_reg", POOL_REG_NUM),
	  status               ("status",                config_reg, 0),
	  op_enable            ("op_enable",             config_reg, 1),
	  kernel_addr          ("kernel_addr",           config_reg, 2),
	  data_in_address      ("data_in_address",       config_reg, 3),
	  data_out_address     ("data_out_address",      config_reg, 4),
	  data_cube_in_width   ("data_cube_in_width",    config_reg, 5),
	  data_cube_in_height  ("data_cube_in_height",   config_reg, 6),
	  data_cube_in_channel ("data_cube_in_channel",  config_reg, 7),
	  data_cube_out_widhth ("data_cube_out_widhth",  config_reg, 8),
	  data_cube_out_height ("data_cube_out_height",  config_reg, 9),
	  data_cube_out_channel("data_cube_out_channel", config_reg, 10),
	  filter_width         ("filter_width",          config_reg, 11),
	  filter_stride        ("filter_stride",         config_reg, 12),
	  zero_padding         ("zero_padding",          config_reg, 13),
	  data_buffer("data_buffer", POOL_BUFFER_SIZE / sizeof(unsigned char))
{
	/* Initialize */
	config_reg.initialize(0);
	data_buffer.initialize(0);

	/* Callback registrations */
	set_word_write_callback(op_enable, SCML2_CALLBACK(WriteOPEnable), scml2::NEVER_SYNCING);

	t_adapter(data_buffer);

	SC_THREAD(ConvEngineThread);
}

void ConvEngine::ConvEngineThread() {
	while(true) {
		while(op_enable != 1) {
			wait(event_reg_op_enable);
		}
		status = 1;
		DoConv();
		op_enable = 0;
		status = 0;
	}
}

bool ConvEngine::WriteOPEnable(const uint &enable) {
	op_enable = enable;
	if(op_enable == 1) {
		event_reg_op_enable.notify(SC_ZERO_TIME);
	}

	return true;
}


void ConvEngine::PrintConfigReg() const{
	cout << "== " << this->name() << " ==\n"
	     << "[Config bus view]\n"
	     << "                  status = " << status << '\n'
	     << "               op_enable = " << op_enable << '\n'
	     << "          kernel_address = " << kernel_addr << '\n'
	     << "         data_in_address = " << data_in_address << '\n'
	     << "        data_out_address = " << data_out_address << '\n'
	     << "      data_cube_in_width = " << data_cube_in_width << '\n'
	     << "     data_cube_in_height = " << data_cube_in_height << '\n'
	     << "    data_cube_in_channel = " << data_cube_in_channel << '\n'
	     << "    data_cube_out_widhth = " << data_cube_out_widhth << '\n'
	     << "    data_cube_out_height = " << data_cube_out_height << '\n'
	     << "   data_cube_out_channel = " << data_cube_out_channel << '\n'
	     << "            filter_width = " << filter_width << '\n'
	     << "           filter_stride = " << filter_stride << '\n'
	     << "            zero_padding = " << zero_padding << '\n'
	     << "== End ==\n" << endl;
}

void ConvEngine::DoConv() {
	cout << "= " << sc_time_stamp().to_string() << " =\n"
	     << "== " << this->name() << " starts doing convolution ==\n\n";
//#ifdef DEBUG
	PrintConfigReg();
//#endif
    for(uint c = 0; c < data_cube_out_channel.get(); ++c){
    for(uint h = 0; h < data_cube_out_height.get() ; ++h){
    for(uint w = 0; w < data_cube_out_widhth.get() ; ++w){
        float o_psum = 0;
        for(uint rc = 0; rc < data_cube_in_channel.get(); ++rc){
        for(uint rh = 0; rh < filter_width.get(); ++rh){
        for(uint rw = 0; rw < filter_width.get(); ++rw){
            // Calculate index for input data and kernel
            int Ih = filter_stride.get() * h + rh;
            int Iw = filter_stride.get() * w + rw;
            int Iidx = rc * data_cube_in_height.get() * data_cube_in_width.get()
                     + Ih * data_cube_in_width.get() + Iw;
            int Kidx = c * data_cube_in_channel.get() * filter_width.get() * filter_width.get()
                     + rh * filter_width.get() + rw;
            // load data from local buffer
            float i_feature, i_kernel;
            data_buffer.get((data_in_address & 0xFFFFF) + Iidx * sizeof(float),
            reinterpret_cast<unsigned char*>(&i_feature), sizeof(float));
            data_buffer.get((kernel_addr & 0xFFFFF) + Kidx * sizeof(float),
            reinterpret_cast<unsigned char*>(&i_kernel), sizeof(float));
            // Computation
            o_psum += i_feature * i_kernel; 
        }}}
        int data_out_offset = c * data_cube_out_height.get() * data_cube_out_widhth.get()
                            + h * data_cube_out_widhth.get() + w;
        data_buffer.put((data_out_address & 0xFFFFF) + data_out_offset * sizeof(float),
        reinterpret_cast<unsigned char*>(&o_psum), sizeof(float));
    }}}
    // The following wait command will determine the delay of the convolution operation, 
    //we need to deduce an equation from HLS simulation results.
    wait(data_cube_out_channel.get() * data_cube_out_height.get() * data_cube_out_widhth.get() * filter_width.get() * filter_width.get() * pool_period);

    cout << "= " << sc_time_stamp().to_string() << " =\n"
         << "== " << this->name() << " finishes doing convolution ==\n" << endl;
}
