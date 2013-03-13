#ifndef c04d8f4e54f
#define c04d8f4e54f

#include "globals.h"
#include <stdio.h>
#include <stdlib.h>

status init_array(generic_ptr * * a,
				size_t const size)
{
	generic_ptr * temp =
		(generic_ptr*) calloc(size, sizeof(generic_ptr));
	if (temp == NULL) {
		return ERROR;
	}
	*a = temp;
	for (size_t i=0; i!= size; ++i) {
		(*a)[i] = NULL;
	}
	return OK;
}

status set(generic_ptr a[],
			size_t const size,
			size_t const index,
			generic_ptr const val)
{
	if (index >= size){
		return ERROR;
	}
	a[index] = val;
	return OK;
}

status get(generic_ptr a[],
		size_t const size,
		size_t const index,
		generic_ptr * const val)
{
	if (index >= size) {
		return ERROR;
	}
	*val = a[index];
	return OK;
}

void destroy_array(generic_ptr * * a,
					size_t const size,
					void (*p_func_f)())
{
	for (size_t i=0; i!= size; ++i){
		(*p_func_f)(&(*a)[i]);
		(*a)[i]=NULL;
	}
	free(*a);
	*a=NULL;
}
#endif
