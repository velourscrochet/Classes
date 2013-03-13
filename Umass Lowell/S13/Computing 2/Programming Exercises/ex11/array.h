//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 11         //
//  3-2-13              //
//  array.h             //
//**********************//

#ifndef ARRAY_H
#define ARRAY_H

#include "globals.h"

typedef struct array array;

extern status init_array(array * * a,
                        size_t const size);

extern status set(array * a,
                size_t const index,
                generic_ptr const val);

extern status get(array * a,
                size_t const index,
                generic_ptr * const val);

extern void destroy_array(array * * a,
                        void (*p_func_f)());

extern size_t array_size(array * a);

#endif //ARRAY_H
