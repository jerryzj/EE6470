#pragma once

#include <scml2.h>

#include "common/memory_map.h"

enum eDMAType {is_engine_type = 0, is_bridge_type = 1};

class DMA : public sc_module {
public:
	SC_HAS_PROCESS(DMA);
	DMA(const sc_module_name &name,
	    const eDMAType type,
	    const unsigned long long local_start_address,
	    const unsigned long long local_end_address);
	~DMA();

	/* Port list */
	scml2::initiator_socket<32> global_i_socket;
	scml2::initiator_socket<32> local_i_socket;

	/* Config bus view */
	scml2::memory<uint> config_reg;

public:
	/* Methods */
	void PrintConfigReg() const;

	/* Main thread */
	void ChannelThread0();
	void ChannelThread1();
	void ChannelThread2();
	void ChannelThread3();
	void ChannelThread4();
	void ChannelThread5();
	void ChannelThread6();
	void ChannelThread7();
	void ChannelThread8();
	void ChannelThread9();
	void ChannelThread10();
	void ChannelThread11();
	void ChannelThread12();
	void ChannelThread13();
	void ChannelThread14();
	void ChannelThread15();

	/* Methods */
	void DoDMA(uint ch_index);
	void ChannelThread(uint ch_index);

	/* Write callback methods for event driven config register */
	bool WriteMode(const uint &dma_mode);
	bool WriteChannelEnable_0(const uint &dma_channel_enable);
	bool WriteChannelEnable_1(const uint &dma_channel_enable);
	bool WriteChannelEnable_2(const uint &dma_channel_enable);
	bool WriteChannelEnable_3(const uint &dma_channel_enable);
	bool WriteChannelEnable_4(const uint &dma_channel_enable);
	bool WriteChannelEnable_5(const uint &dma_channel_enable);
	bool WriteChannelEnable_6(const uint &dma_channel_enable);
	bool WriteChannelEnable_7(const uint &dma_channel_enable);
	bool WriteChannelEnable_8(const uint &dma_channel_enable);
	bool WriteChannelEnable_9(const uint &dma_channel_enable);
	bool WriteChannelEnable_10(const uint &dma_channel_enable);
	bool WriteChannelEnable_11(const uint &dma_channel_enable);
	bool WriteChannelEnable_12(const uint &dma_channel_enable);
	bool WriteChannelEnable_13(const uint &dma_channel_enable);
	bool WriteChannelEnable_14(const uint &dma_channel_enable);
	bool WriteChannelEnable_15(const uint &dma_channel_enable);

	/* Config bus view aliases */
	scml2::reg<uint> status;
	scml2::reg<uint> mode;

	scml2::reg<uint>* channel_enable [DMA_CHANNEL_NUM];
	scml2::reg<uint>* source_address [DMA_CHANNEL_NUM];
	scml2::reg<uint>* dest_address   [DMA_CHANNEL_NUM];
	scml2::reg<uint>* transfer_length[DMA_CHANNEL_NUM];
	scml2::reg<uint>* transfer_type  [DMA_CHANNEL_NUM];
	scml2::reg<uint>* line_length    [DMA_CHANNEL_NUM];
	scml2::reg<uint>* line_stride    [DMA_CHANNEL_NUM];

	std::vector<sc_event> event_channel_enable;

	eDMAType type_;
	unsigned long long local_start_address_;
	unsigned long long local_end_address_;

	sc_time dma_period;
};
