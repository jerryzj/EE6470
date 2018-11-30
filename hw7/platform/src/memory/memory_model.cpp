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

template <typename T>
void MemoryModel<T>::memory_load( const unsigned int begin, unsigned int size, const char* const file_name ) {
	ifstream input;
	unsigned char *data_buffer;
	data_buffer = new unsigned char[size];
	memset ( data_buffer, 0, sizeof(*data_buffer)*size ); //fill 0 to data_buffer

	input.open(file_name, ios::in | ios::binary);
	if(!input){
		cerr<<"memory::load(): Could not open input file:" << file_name <<endl;
		cerr<<"Simulation aborted.";
		exit(1);
	}
	else if((begin + size) > (memory_bank.get_size() * memory_bank.get_width()))
	{
		cerr<<"TlmMemory::load(): "<<  begin+size <<" is out of the bound" <<endl;
		cerr<<"Simulation aborted.";
		exit(1);
	}
	else{
		input.read( reinterpret_cast<char*>(data_buffer), size );
		if ( ! input ) {
			cerr<<"TlmMemory::load(): only " << input.gcount() << " could be read"<< endl;
		}
		input.close();
	}
	//Assume it's little endian. Big endian need to implement.
	memory_bank.put_debug(begin, data_buffer, size);
	delete data_buffer;
}

template <typename T>
void MemoryModel<T>::memory_dump( const unsigned int begin, unsigned int size, const char* const file_name ) {
	ofstream output;
	unsigned char *data_buffer;
	data_buffer = new unsigned char[size];
	memset ( data_buffer, 0, sizeof(*data_buffer)*size ); //fill 0 to data_buffer

	output.open(file_name, ios::out | ios::binary);
	if(!output){
		cerr<<"TlmMemory::dump(): Could not open output file:" << file_name <<endl;
		cerr<<"Simulation aborted.";
		exit(1);
	}
	else if((begin + size) > (memory_bank.get_size() * memory_bank.get_width()))
	{
		cerr<<"TlmMemory::dump(): "<<  begin+size <<" is out of the bound" <<endl;
		cerr<<"Simulation aborted.";
		exit(1);
	}
	else{
		//Assume it's little endian. Big endian need to implement.
		memory_bank.get_debug(begin, data_buffer, size);
		output.write(reinterpret_cast<const char*>(data_buffer), size);
		output.close();
		delete data_buffer;
	}
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
