#include "pool_engine.h"

#include <limits>

#include "common/memory_map.h"

PoolEngine::PoolEngine(const sc_module_name &name)
	: sc_module(name),
	  t_socket("t_socket"),
	  t_adapter("t_adapter", t_socket),
	  pool_period(CLOCK_PERIOD, SC_NS),
	  config_reg("config_reg", POOL_REG_NUM),
	  status               ("status",                config_reg, 0),
	  op_enable            ("op_enable",             config_reg, 1),
	  pool_function        ("pool_function",         config_reg, 2),
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

	SC_THREAD(PoolEngineThread);
}

void PoolEngine::PoolEngineThread() {
	while(true) {
		while(op_enable != 1) {
			wait(event_reg_op_enable);
		}
		status = 1;
		DoPooling();
		op_enable = 0;
		status = 0;
	}
}

bool PoolEngine::WriteOPEnable(const uint &enable) {
	op_enable = enable;
	if(op_enable == 1) {
		event_reg_op_enable.notify(SC_ZERO_TIME);
	}

	return true;
}


void PoolEngine::PrintConfigReg() const{
	cout << "== " << this->name() << " ==\n"
	     << "[Config bus view]\n"
	     << "                  status = " << status << '\n'
	     << "               op_enable = " << op_enable << '\n'
	     << "           pool_function = " << pool_function << '\n'
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

void PoolEngine::DoPooling() {
	cout << "= " << sc_time_stamp().to_string() << " =\n"
	     << "== " << this->name() << " starts doing pooling ==\n\n";
#ifdef DEBUG
	PrintConfigReg();
#endif

	/* Still can update status accoding to working status while doing pooling */
	/* Assume data type is floating point 32 */

	ePoolFunction function(static_cast<ePoolFunction>(pool_function.get()));

	for(uint out_ch_idx = 0; out_ch_idx < data_cube_out_channel.get(); out_ch_idx++) {
		for(uint out_h_idx = 0; out_h_idx < data_cube_out_height.get(); out_h_idx++) {
			for(uint out_w_idx = 0; out_w_idx < data_cube_out_widhth.get(); out_w_idx++) {
				/* Pooling window coverage on input data plane */
				int win_h_start(out_h_idx * filter_stride - zero_padding);
				int win_w_start(out_w_idx * filter_stride - zero_padding);
				int win_h_end  (win_h_start + filter_width);
				int win_w_end  (win_w_start + filter_width);

				float temp_data;
				switch(function) {
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
						if((in_h_idx < 0) || (in_h_idx >= static_cast<int>(data_cube_in_height.get()))
							|| (in_w_idx < 0) || (in_w_idx >= static_cast<int>(data_cube_in_width.get()))) {
							switch(pool_function) {
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
							int data_in_offset(out_ch_idx * data_cube_in_height.get() * data_cube_in_width.get()
							                   + in_h_idx * data_cube_in_width.get() + in_w_idx);

							float mem_r_data;
							data_buffer.get((data_in_address & 0xFFFFF) + data_in_offset * sizeof(float),
							                reinterpret_cast<unsigned char*>(&mem_r_data),
							                sizeof(float));

							switch(function) {
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

				uint window_size(filter_width.get() * filter_width.get());
				switch(function) {
				case is_maximum:
				case is_minimum:
					break;
				case is_average:
					temp_data = temp_data / window_size;
					break;
				default: assert(0 && "Pooling Engine hasn't support this function yet.");
				}

				int data_out_offset = out_ch_idx * data_cube_out_height.get() * data_cube_out_widhth.get()
				                      + out_h_idx * data_cube_out_widhth.get() + out_w_idx;

				data_buffer.put((data_out_address & 0xFFFFF) + data_out_offset * sizeof(float),
				                reinterpret_cast<unsigned char*>(&temp_data),
				                sizeof(float));
			}
		}
	}
	wait(data_cube_out_channel.get() * data_cube_out_height.get() * data_cube_out_widhth.get() * filter_width.get() * filter_width.get() * pool_period);

	cout << "= " << sc_time_stamp().to_string() << " =\n"
	     << "== " << this->name() << " finishes doing pooling ==\n" << endl;
}
