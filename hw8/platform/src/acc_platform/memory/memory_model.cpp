#include "memory_model.h"

template <typename T>
MemoryModel<T>::MemoryModel(const sc_module_name &name,
                            unsigned long long size_in_bytes,
                            const sc_time &read_latency,
                            const sc_time &wirte_latency)
	: sc_module(name),
	  memory_bank("memory_bank", size_in_bytes / sizeof(T))
{
	/* Initialization */
	memory_bank.initialize(0);

	/* Set properties of memory bank */
	memory_bank.set_default_read_latency(read_latency);
	memory_bank.set_default_write_latency(wirte_latency);
	memory_bank.enable_dmi();

	// cout << this->name() << " has been instantiated.\n"
	//      << "[Information]\n"
	//      << "    Memory width: " << memory_bank.get_width() << " byte(s)\n"
	//      << "     Memory size: " << memory_bank.get_size() * memory_bank.get_width() << " byte(s)\n"
	//      << "    Read latency: " << memory_bank.get_default_read_latency() << '\n'
	//      << "   Write latency: " << memory_bank.get_default_write_latency() << '\n'
	//      << "             DMI: " << (memory_bank.is_dmi_enabled() ? "Enabled" : "Disabled") << '\n' << endl;
}

/* The explicit template instantiation.
 * C++ Template is merely only a "rule" to generate function<T>().
 * Programmer must explicit instantiate so that function body
 * of MemoryModel<unsigned char> will be generated here.
 */
template class MemoryModel<unsigned char>;
// template class MemoryModel<unsigned short>;
// template class MemoryModel<unsigned int>;
// template class MemoryModel<unsigned long long>;
