#ifndef H
#define H

#include "stack.h"
#include "globals.h"

typedef struct stack stack;

extern status init_stack(stack * const p_S);
extern bool empty_stack(stack const S);
extern status push(stack * const p_S,
					generic_ptr const data);
extern status pop(stack * const p_S, generic_ptr const data);
extern status destroy_stack(stack * const p_S,
						void (*p_fonc_f)(generic_ptr));

#endif

