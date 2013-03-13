#ifndef f51416ff7ed5
#define f51416ff7ed5

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

#endif