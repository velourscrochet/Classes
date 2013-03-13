//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 6          //
//  stack.h             //
//  2-12-13             //
//**********************//

#ifndef H78946521235798555541111
#define H78946521235798555541111

#include <stdlib.h>
#include "globals.h"


struct stack {
    size_t MAXSTACKSIZE;
    generic_ptr * base;
    generic_ptr * top;
};

typedef struct stack stack;

extern status init_stack(stack * * const p_S,
                        size_t const size);

extern bool empty_stack(stack const S);

extern status push(stack * const p_S,
                    generic_ptr const data);

extern status pop(stack * const p_S, generic_ptr const data);

extern void destroy_stack(stack * * const p_S,
                            void (*p_func_f)());

#endif

