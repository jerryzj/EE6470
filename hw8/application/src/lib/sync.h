#ifndef _SYNC_LIB_
#define _SYNC_LIB_

#define NCORE 4

#ifdef __cplusplus
extern "C" {
#endif

int gethartid();

typedef enum {FREE, LOCKED} MutexState;
typedef struct Mutex_t{
	int state;
} Mutex;

void mutex_lock( volatile Mutex* );

void mutex_unlock( volatile Mutex* );

void barrier(const unsigned nwait);

int main(int argc, char** argv);

#ifdef __cplusplus
}
#endif

#endif
