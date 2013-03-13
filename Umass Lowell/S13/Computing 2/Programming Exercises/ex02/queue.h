#ifndef wub
#define wub

#include "globals.h"

typedef struct queue queue;

extern status init_queue (queue * const p_Q);
extern bool empty_queue (queue const Q);
extern status queue_add(queue * const p_Q,
					generic_ptr const data);
extern status queue_remove(queue * const p_Q,
					generic_ptr * const p_data);

extern status destroy_queue(queue * const p_Q,
						void (*p_func_f)(generic_ptr));


#endif
