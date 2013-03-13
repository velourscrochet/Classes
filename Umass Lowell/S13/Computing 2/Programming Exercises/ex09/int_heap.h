//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 9          //
//  int_heap.h          //
//  2-26-13             //
//**********************//


#ifndef INT_HEAP_H
#define INT_HEAP_H

#include "heap.h"

extern status heap_insert_int(heap * const p_H,
                            int const i);

extern status heap_delete_int(heap * const p_H,
                            size_t const index,
                            int * const p_i);

#endif
