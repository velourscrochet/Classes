//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 9          //
//  heap.h              //
//  2-26-13             //
//**********************//


#ifndef HEAP_H
#define HEAP_H

#include "globals.h"
#include <stdbool.h>

typedef struct heap heap;

extern status init_heap(heap * * const p_H,
                        size_t const increment,
                        int (* p_cmp_f)());

extern bool empty_heap(heap * const p_H);

extern status heap_insert(heap * const p_H,
                        generic_ptr const data);

extern status heap_delete(heap * const p_H,
                        size_t const index,
                        generic_ptr * const p_data);

extern void destroy_heap(heap * * const p_H,
                        void (*p_func_f)());



#endif
