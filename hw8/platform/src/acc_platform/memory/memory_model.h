#pragma once

#include <scml2.h>

template <typename T>
class MemoryModel : public sc_module {
public:
	MemoryModel(const sc_module_name &name,
	            unsigned long long size_in_bytes,
	            const sc_time &read_latency = sc_time(0, SC_NS),
	            const sc_time &write_latency = sc_time(0, SC_NS));
	~MemoryModel() {}

	/* Memory bank */
	scml2::memory<T> memory_bank;
};
