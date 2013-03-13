#ifndef ef1abf40c891d588c7fa5e4448
#define ef1abf40c891d588c7fa5e4448

#include "globals.h"
#include "stddef.h"

status init_array(generic_ptr **,
				size_t const size);

status set(generic_ptr a[],
		size_t const size,
		size_t const index,
		generic_ptr const val);

status get(generic_ptr a[],
		size_t const size,
		size_t const index,
		generic_ptr * const val);

void destroy_array(generic_ptr * * a,
				size_t const size,
				void (*p_func_f)());

#endif
