#include "dma.h"

DMA::DMA(const sc_module_name &name,
         const eDMAType type,
         const unsigned long long local_start_address,
         const unsigned long long local_end_address)
    : sc_module(name),
      global_i_socket("global_i_socket"),
      local_i_socket("local_i_socket"),
      config_reg("config_reg", (1 + DMA_CHANNEL_NUM) * 16),
      status("status", config_reg, 0),
      mode("mode", config_reg, 1),
      type_(type),
      local_start_address_(local_start_address),
      local_end_address_(local_end_address),
      dma_period(CLOCK_PERIOD, SC_NS),
      event_channel_enable(DMA_CHANNEL_NUM)
{
	/* Initialization */
	config_reg.initialize(0);
	for(int i = 0; i < DMA_CHANNEL_NUM; i++) {
		channel_enable[i]  = new scml2::reg<uint>("channel_enable_" + std::to_string(i),  config_reg, 16 * (i + 1));
		source_address[i]  = new scml2::reg<uint>("source_address_" + std::to_string(i),  config_reg, 16 * (i + 1) + 1);
		dest_address[i]    = new scml2::reg<uint>("dest_address_" + std::to_string(i),    config_reg, 16 * (i + 1) + 2);
		transfer_length[i] = new scml2::reg<uint>("transfer_length_" + std::to_string(i), config_reg, 16 * (i + 1) + 3);
		transfer_type[i]   = new scml2::reg<uint>("transfer_type_" + std::to_string(i),   config_reg, 16 * (i + 1) + 4);
		line_length[i]     = new scml2::reg<uint>("line_length_" + std::to_string(i),     config_reg, 16 * (i + 1) + 5);
		line_stride[i]     = new scml2::reg<uint>("line_stride_" + std::to_string(i),     config_reg, 16 * (i + 1) + 6);
	}

	/* Callback registrations */
	set_word_write_callback(mode, SCML2_CALLBACK(WriteMode), scml2::NEVER_SYNCING);

	set_word_write_callback(*channel_enable[0], SCML2_CALLBACK(WriteChannelEnable_0), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[1], SCML2_CALLBACK(WriteChannelEnable_1), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[2], SCML2_CALLBACK(WriteChannelEnable_2), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[3], SCML2_CALLBACK(WriteChannelEnable_3), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[4], SCML2_CALLBACK(WriteChannelEnable_4), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[5], SCML2_CALLBACK(WriteChannelEnable_5), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[6], SCML2_CALLBACK(WriteChannelEnable_6), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[7], SCML2_CALLBACK(WriteChannelEnable_7), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[8], SCML2_CALLBACK(WriteChannelEnable_8), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[9], SCML2_CALLBACK(WriteChannelEnable_9), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[10], SCML2_CALLBACK(WriteChannelEnable_10), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[11], SCML2_CALLBACK(WriteChannelEnable_11), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[12], SCML2_CALLBACK(WriteChannelEnable_12), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[13], SCML2_CALLBACK(WriteChannelEnable_13), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[14], SCML2_CALLBACK(WriteChannelEnable_14), scml2::NEVER_SYNCING);
	set_word_write_callback(*channel_enable[15], SCML2_CALLBACK(WriteChannelEnable_15), scml2::NEVER_SYNCING);

	// cout << this->name() << " has been instantiated.\n"
	//      << "[Information]\n"
	//      << "           Local address space: 0x" << hex << local_start_address_ << " ~ 0x" << local_end_address_ << dec << '\n'
	//      << "              Operating period: " << dma_period << '\n' << endl;

	SC_THREAD(ChannelThread0);
	SC_THREAD(ChannelThread1);
	SC_THREAD(ChannelThread2);
	SC_THREAD(ChannelThread3);
	SC_THREAD(ChannelThread4);
	SC_THREAD(ChannelThread5);
	SC_THREAD(ChannelThread6);
	SC_THREAD(ChannelThread7);
	SC_THREAD(ChannelThread8);
	SC_THREAD(ChannelThread9);
	SC_THREAD(ChannelThread10);
	SC_THREAD(ChannelThread11);
	SC_THREAD(ChannelThread12);
	SC_THREAD(ChannelThread13);
	SC_THREAD(ChannelThread14);
	SC_THREAD(ChannelThread15);
}

DMA::~DMA() {
	for(int i = 0; i < DMA_CHANNEL_NUM; i++) {
		if(channel_enable[i])  delete channel_enable[i];
		if(source_address[i])  delete source_address[i];
		if(dest_address[i])    delete dest_address[i];
		if(transfer_length[i]) delete transfer_length[i];
		if(transfer_type[i])   delete transfer_type[i];
		if(line_length[i])     delete line_length[i];
		if(line_stride[i])     delete line_stride[i];
	}
}

void DMA::ChannelThread0() {
	ChannelThread(0);
}

void DMA::ChannelThread1() {
	ChannelThread(1);
}

void DMA::ChannelThread2() {
	ChannelThread(2);
}

void DMA::ChannelThread3() {
	ChannelThread(3);
}

void DMA::ChannelThread4() {
	ChannelThread(4);
}

void DMA::ChannelThread5() {
	ChannelThread(5);
}

void DMA::ChannelThread6() {
	ChannelThread(6);
}

void DMA::ChannelThread7() {
	ChannelThread(7);
}

void DMA::ChannelThread8() {
	ChannelThread(8);
}

void DMA::ChannelThread9() {
	ChannelThread(9);
}

void DMA::ChannelThread10() {
	ChannelThread(10);
}

void DMA::ChannelThread11() {
	ChannelThread(11);
}

void DMA::ChannelThread12() {
	ChannelThread(12);
}

void DMA::ChannelThread13() {
	ChannelThread(13);
}

void DMA::ChannelThread14() {
	ChannelThread(14);
}

void DMA::ChannelThread15() {
	ChannelThread(15);
}

void DMA::ChannelThread(uint ch_index) {
	while(true) {
		while((mode != 1) || (*channel_enable[ch_index] != 1)) {
			wait(event_channel_enable[ch_index]);
		}
		status = status ^ (1 << ch_index);
		DoDMA(ch_index);
		status = status ^ (1 << ch_index);
	}
}

void DMA::PrintConfigReg() const {
	cout << "== " << this->name() << "\'s config registers ==\n"
	     << "[Common]\n"
	     << "            status = "   << status << '\n'
	     << "              mode = "   << mode << '\n';
	for(int i = 0; i < DMA_CHANNEL_NUM; i++) {
		cout << "[Channel " << i << "]\n"
		     << "    channel_enable = "   << *channel_enable[i] << '\n'
		     << "    source_address = 0x" << hex << *source_address[i] << '\n'
		     << "      dest_address = 0x" << *dest_address[i] << dec << '\n'
		     << "   transfer_length = "   << *transfer_length[i] << '\n'
		     << "     transfer_type = "   << *transfer_type[i] << '\n'
		     << "       line_length = "   << *line_length[i] << '\n'
		     << "       line_stride = "   << *line_stride[i] << '\n';
	}
	cout << "== End ==\n" << endl;
}

void DMA::DoDMA(uint ch_index) {
//#ifdef DEBUG
	cout << "= " << sc_time_stamp().to_string() << " =\n"
	     << "== " << this->name() << " ch." << ch_index
	     << " starts transferring data ==\n\n";
//	PrintConfigReg();
//#endif
	uint i = ch_index;

	bool is_global_write((*source_address[i] >= local_start_address_) && (*source_address[i] <= local_end_address_));
	bool is_global_read((*dest_address[i] >= local_start_address_) && (*dest_address[i] <= local_end_address_));

	unsigned char* dma_buffer(nullptr);
	unsigned long long local_address(0);
	unsigned long long global_address(0);
	uint burst_beat_num(0);

	if(is_global_write) {
		switch(type_) {
		case is_engine_type:
			local_address = *source_address[i] - local_start_address_;
			break;
		case is_bridge_type:
			local_address = *source_address[i];
			break;
		default: assert(0 && "DMA doesn't support this DMA type.");
		}
		global_address = *dest_address[i];
		if(*line_length[i] == 0) {
			/* 1D tranfer */
			dma_buffer = new unsigned char[*transfer_length[i]];
			local_i_socket.read<unsigned char>(local_address, dma_buffer, *transfer_length[i]);
			global_i_socket.write<unsigned char>(global_address, dma_buffer, *transfer_length[i]);

			burst_beat_num = ceil(static_cast<float>(*transfer_length[i]) / BUS_WIDTH);
			wait(burst_beat_num * dma_period);
		} else {
			/* 2D tranfer */
			dma_buffer = new unsigned char[*line_length[i]];
			for(uint j = 0; j < *transfer_length[i]; j += *line_length[i]) {
				local_i_socket.read<unsigned char>(local_address, dma_buffer, *line_length[i]);
				global_i_socket.write<unsigned char>(global_address, dma_buffer, *line_length[i]);
				local_address  += *line_stride[i];
				global_address += *line_length[i];

				burst_beat_num = ceil(static_cast<float>(*line_length[i]) / BUS_WIDTH);
				wait(burst_beat_num * dma_period);
			}
		}
	} else if(is_global_read) {
		switch(type_) {
		case is_engine_type:
			local_address  = *dest_address[i] - local_start_address_;
			break;
		case is_bridge_type:
			local_address  = *dest_address[i];
			break;
		default: assert(0 && "DMA doesn't support this DMA type.");
		}
		global_address = *source_address[i];
		if(*line_length[i] == 0) {
			/* 1D tranfer */
			dma_buffer = new unsigned char[*transfer_length[i]];
			global_i_socket.read<unsigned char>(global_address, dma_buffer, *transfer_length[i]);
			local_i_socket.write<unsigned char>(local_address, dma_buffer, *transfer_length[i]);

			burst_beat_num = ceil(static_cast<float>(*transfer_length[i]) / BUS_WIDTH);
			wait(burst_beat_num * dma_period);
		} else {
			/* 2D tranfer */
			dma_buffer = new unsigned char[*line_length[i]];
			for(uint j = 0; j < *transfer_length[i]; j += *line_length[i]) {
				global_i_socket.read<unsigned char>(global_address, dma_buffer, *line_length[i]);
				local_i_socket.write<unsigned char>(local_address, dma_buffer, *line_length[i]);
				global_address += *line_stride[i];
				local_address  += *line_length[i];

				burst_beat_num = ceil(static_cast<float>(*line_length[i]) / BUS_WIDTH);
				wait(burst_beat_num * dma_period);
			}
		}
	} else
		assert(0 && "DMA operation error.");
	if(dma_buffer) delete[] dma_buffer;

	*channel_enable[i] = 0;

//#ifdef DEBUG
	cout << "= " << sc_time_stamp().to_string() << " =\n"
	     << "== " << this->name() << " ch." << ch_index
	     << " finishes transferring data ==\n" << endl;
//	PrintConfigReg();
//#endif
}

bool DMA::WriteMode(const uint &dma_mode) {
	mode = dma_mode;
	if(mode == 1) {
		for(uint i = 0; i < DMA_CHANNEL_NUM; i++) {
			if(*channel_enable[i] == 1) {
				event_channel_enable[i].notify();
			}
		}
	}

	return true;
}

bool DMA::WriteChannelEnable_0(const uint &dma_channel_enable) {
	*channel_enable[0] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[0] == 1))
		event_channel_enable[0].notify();

	return true;
}

bool DMA::WriteChannelEnable_1(const uint &dma_channel_enable) {
	*channel_enable[1] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[1] == 1))
		event_channel_enable[1].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_2(const uint &dma_channel_enable) {
	*channel_enable[2] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[2] == 1))
		event_channel_enable[2].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_3(const uint &dma_channel_enable) {
	*channel_enable[3] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[3] == 1))
		event_channel_enable[3].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_4(const uint &dma_channel_enable) {
	*channel_enable[4] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[4] == 1))
		event_channel_enable[4].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_5(const uint &dma_channel_enable) {
	*channel_enable[5] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[5] == 1))
		event_channel_enable[5].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_6(const uint &dma_channel_enable) {
	*channel_enable[6] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[6] == 1))
		event_channel_enable[6].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_7(const uint &dma_channel_enable) {
	*channel_enable[7] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[7] == 1))
		event_channel_enable[7].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_8(const uint &dma_channel_enable) {
	*channel_enable[8] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[8] == 1))
		event_channel_enable[8].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_9(const uint &dma_channel_enable) {
	*channel_enable[9] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[9] == 1))
		event_channel_enable[9].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_10(const uint &dma_channel_enable) {
	*channel_enable[10] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[10] == 1))
		event_channel_enable[10].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_11(const uint &dma_channel_enable) {
	*channel_enable[11] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[11] == 1))
		event_channel_enable[11].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_12(const uint &dma_channel_enable) {
	*channel_enable[12] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[12] == 1))
		event_channel_enable[12].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_13(const uint &dma_channel_enable) {
	*channel_enable[13] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[13] == 1))
		event_channel_enable[13].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_14(const uint &dma_channel_enable) {
	*channel_enable[14] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[14] == 1))
		event_channel_enable[14].notify();
	
	return true;
}

bool DMA::WriteChannelEnable_15(const uint &dma_channel_enable) {
	*channel_enable[15] = dma_channel_enable;
	if((mode == 1) && (*channel_enable[15] == 1))
		event_channel_enable[15].notify();
	
	return true;
}

