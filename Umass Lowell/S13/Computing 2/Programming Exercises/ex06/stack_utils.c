//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 6          //
//  stack_utils.c       //
//  2-12-13             //
//**********************//

#ifndef H78521235798434567890
#define H78521235798434567890

#include "globals.h"
#include "stack.h"
#include "stack_utils.h"

status top(stack * const p_S,
            generic_ptr * const p_data)
{
    generic_ptr temp;
    if (pop(p_S, &temp) == ERROR ||
        push(p_S, temp) == ERROR)
    {
        return ERROR;
    }//if
    *p_data = temp;
    return OK;
}//top



#endif
