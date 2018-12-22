#include <stdio.h>
#include <assert.h>

#include "sync.h"

//user will overwrite this function
extern void thread_entry(int cid, int nc);

// Defined in imperas.S, which is semihosted by OVP
extern int impProcessorId();
int gethartid() {
	int id = impProcessorId();
	assert(id < NCORE);
	return id;
}

/* 
 * This is an atomic operation defined in 
 * https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf
 * page 42.
 *
 * If the value in reg is the same as oldval, 
 *    assign newval to reg and return 1.
 * Otherwise do nothing, return 0.
 *
 * */ 
int compare_and_swap(volatile int *reg, int oldval, int newval);
int fetch_and_add( void* mem, int val );

// initialize array with zero
static int local_sense[NCORE] = { [0 ... NCORE-1] = 0 };

int get_threadsense() {
	int id = gethartid();
	assert(id < NCORE);
	return local_sense[id];
}

void set_threadsense(int val){
	int id = gethartid();
	assert(id < NCORE);
	local_sense[id] = val;
}

void mutex_lock( volatile Mutex* mutex ) {
	while( compare_and_swap( &mutex->state, FREE, LOCKED ) );
}

void mutex_unlock( volatile Mutex* mutex ) {
	assert( !compare_and_swap( &mutex->state, LOCKED, FREE ) );
}

// Sense-Reversing Barrier
void barrier(const unsigned nwait) {
	static int narrived = -1; 
	static int global_sense = 0;
	set_threadsense(1-get_threadsense());

	const int new_arrive_val = fetch_and_add((void*)&narrived, 1);
	if (new_arrive_val  == nwait-2 ) {
		// last arriver sets flag
		narrived = -1;
		global_sense = get_threadsense();
	} else {
		while( global_sense != get_threadsense() ) {
			// wait global sense
		}
	}
}

int main(int argc, char** argv) {
	int ncore = NCORE;
	int coreid = gethartid();
	thread_entry(coreid, ncore);

	barrier(ncore);
	return 0;
}
