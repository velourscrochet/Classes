//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 9          //
//  int_heap.c          //
//  2-26-13             //
//**********************//


#ifndef INT_HEAP_C
#define INT_HEAP_C

#include "int_heap.h"

status heap_insert_int(heap * const p_H,
                        int const i)
{
    int * p = (int *) malloc (sizeof(int));
    if (p==NULL)
        return ERROR;

    *p = i;
    if (heap_insert(p_H, p) == ERROR)
    {
        free(p);
        return ERROR;
    }//if

    return OK;
}//heap_insert_int

status heap_delete_int(heap * const p_H,
                        size_t const index,
                        int * const p_i)
{
    int * p_temp;
    if (heap_delete(p_H, index, (generic_ptr *)&p_temp) == ERROR)
        return ERROR;

    *p_i = *p_temp;
    free(p_temp);
    return OK;
}//heap_delete_int













#endif
