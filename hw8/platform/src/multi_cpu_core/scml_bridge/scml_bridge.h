#pragma once

#include <scml2.h>
#include "tlm_utils/simple_target_socket.h"

class ScmlBridge : public sc_module {
public:
	ScmlBridge(const sc_module_name &name,
	           const unsigned long long base_address = 0);
	~ScmlBridge() {}

	/* Port list */
	tlm_utils::simple_target_socket<ScmlBridge> t_socket;
	scml2::initiator_socket<32> i_socket;

private:
	void b_transport(tlm::tlm_generic_payload &payload, sc_time &delay);

	unsigned long long base_address_;
};
