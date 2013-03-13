#ifndef wub
#define wub

#include "globals.h"

typedef struct heap heap;

extern status init_heap(heap * const p_H);
extern bool empty_heap(heap * const p_H);
extern status heap_insert(heap * const p_H, 
					 generic_ptr * const data,
					int (*p_cmp_f)(generic_ptr, generic_ptr));
extern status heap_delete(heap * const p_H,
					unsigned int index,
					generic_ptr * const p_data,
					int (*p_cmp_f)(generic_ptr, generic_ptr));
extern status destroy_heap(heap * const p_H,
						void (*p_func_f)(generic_ptr));


#endif
