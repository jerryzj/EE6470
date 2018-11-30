#include "scml_bridge.h"

ScmlBridge::ScmlBridge(const sc_module_name &name,
                       const unsigned long long base_address)
	: sc_module(name),
	  t_socket("t_socket"),
	  i_socket("i_socket"),
	  base_address_(base_address)
{
	t_socket.register_b_transport(this, &ScmlBridge::b_transport);
}

void ScmlBridge::ScmlBridge::b_transport(
	tlm::tlm_generic_payload &payload,
	sc_time &delay)
{
	tlm::tlm_command cmd = payload.get_command();
	sc_dt::uint64    adr = payload.get_address() + base_address_;
	unsigned char*   ptr = payload.get_data_ptr();
	unsigned int     len = payload.get_data_length();

	if(cmd == tlm::TLM_READ_COMMAND) {
		if(i_socket.read<unsigned char>(adr, ptr, len, delay))
			payload.set_response_status(tlm::TLM_OK_RESPONSE);
		else
			payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
	} else if(cmd == tlm::TLM_WRITE_COMMAND) {
		if(i_socket.write<unsigned char>(adr, ptr, len, delay))
			payload.set_response_status(tlm::TLM_OK_RESPONSE);
		else
			payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
	} else
		payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
}
