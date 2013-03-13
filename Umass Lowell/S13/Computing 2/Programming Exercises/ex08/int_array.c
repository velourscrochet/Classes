//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 8          //
//  2-21-13             //
//  int_array.c         //
//**********************//

#include "int_array.h"

status set_int(array * const a,
                size_t const index,
                int const i)
{
    int * p = (int *) malloc(sizeof(int));
    if (p == NULL)
        return ERROR;
    
    *p = i;
    if (set (a, index, p) == ERROR)
    {
        free(p);
        return ERROR;
    }//if

    return OK;
}

