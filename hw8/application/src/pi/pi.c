#include <stdio.h>
#include <stdlib.h>
#include "sync.h"

/*
 *  Use Gregory-Leibniz Series to calculate Pi:
 *  
 *    Pi/4 = 1 - (1/3) + (1/5) - (1/7) + ....
 * 
 */

double pi_over_4 = 0;
Mutex mutex;

void thread_entry(int cid, int nc) {
	unsigned total_terms = 300;

	unsigned num_terms_per_thread = (total_terms + nc - 1 ) / nc;
	unsigned begin_idx = num_terms_per_thread * cid;
	unsigned end_idx;
	if (cid == nc - 1) {
		end_idx = total_terms;
	} else {
		end_idx = begin_idx + num_terms_per_thread;
	}

	double factor = begin_idx % 2 ? -1.0 : 1.0;

	double local_sum = 0, i;
	for (i = begin_idx ; i < end_idx; i++, factor = -factor) {
		local_sum += factor / (2 * i + 1);
	}

	mutex_lock(&mutex);
	pi_over_4 += local_sum;
	mutex_unlock(&mutex);

	barrier(nc);

	if (cid == 0) {
		printf("\nPi = %f\n", (pi_over_4)*4);
	}

	exit(0);
}
