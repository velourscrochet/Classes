#ifndef abf40c891d588c7fa5e4448
#define abf40c891d588c7fa5e4448

#include "globals.h"
#include "stddef.h"
#include "array.h"
#include "array.c"
#include "stdio.h"
#include "stdlib.h"

void destroy_generic_ptr(generic_ptr * p)
{
        free (*p);
        *p = NULL;
}


int main(int argc, char * * argv)
{
	size_t const a_size = 3;
	generic_ptr * a;
	if (init_array(&a, a_size) == ERROR){
		return ERROR; //EXIT_FAILURE;
	}

	if (set(a, a_size, 3, NULL) != ERROR){
		return ERROR; //EXIT_FAILURE;
	}
	if (set(a, a_size, 2, NULL) == ERROR){
		return ERROR;// EXIT_FAILURE;
	}
	destroy_array(&a, a_size,destroy_generic_ptr);
	if (a!= NULL){
		return ERROR;
	}

	return OK;
}



#endif
