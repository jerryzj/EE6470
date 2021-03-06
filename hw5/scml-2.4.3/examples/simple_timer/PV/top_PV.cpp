/***************************************************************************
 * Copyright 1996-2017 Synopsys, Inc.
 *
 * This Synopsys software and all associated documentation are proprietary
 * to Synopsys, Inc. and may only be used pursuant to the terms and
 * conditions of a written license agreement with Synopsys, Inc.
 * All other use, reproduction, modification, or distribution of the
 * Synopsys software or the associated documentation is strictly prohibited.
 ***************************************************************************/

// Purpose: Top level source file for simple timer at PV level

#include "top_PV.h"

#ifdef _WIN32
  #ifndef __PRETTY_FUNCTION__
    #define __PRETTY_FUNCTION__ __FUNCTION__
  #endif
#endif
//-------------------------------------------------------------------------  
// Constructor	
//
top::top(sc_module_name nm)
   : sc_module(nm) {
    
    cout << name() << " : " << __PRETTY_FUNCTION__ << " : constructor" << endl;
				    
    // Instantiate the PV modules
    
    pI_simple_timer_PV = new simple_timer_PV("I_simple_timer_PV");
    pI_simple_timer_PV_TB = new simple_timer_PV_TB("I_simple_timer_PV_TB");
    
    //create the clock generator
    
    pI_scml_clock = new scml_clock("I_scml_clock", 1.0, SC_NS);
		
    // Bindings
    
    pI_simple_timer_PV_TB->p_PV(pI_simple_timer_PV->p_PV);
    pI_simple_timer_PV->clk_in(*pI_scml_clock);
		
} // end constructor


//-------------------------------------------------------------------------  
// Destructor
//
top::~top() {
    delete pI_simple_timer_PV;
    delete pI_simple_timer_PV_TB;
    delete pI_scml_clock;
}
