#include <stdio.h>
#include "sync.h"

void thread_entry(int cid, int nc) {
    printf("\nHello from CPU%d\n", cid);
}
