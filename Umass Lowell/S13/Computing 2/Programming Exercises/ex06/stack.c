//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 6          //
//  stack.c             //
//  2-12-13             //
//**********************//

#ifndef H7894652123579844
#define H7894652123579844

#include "globals.h"
#include "stack.h"

#include <stdlib.h>

struct stack {
    size_t MAXSTACKSIZE;
    generic_ptr * base;
    generic_ptr * top;
};

static size_t num_elements(stack * p_S)
{
    return p_S->top - p_S->base;
}

status init_stack(stack * * const p_S,
                size_t const size)
{
    stack * temp = (stack *) malloc(sizeof(stack));

    if (temp == NULL)
    {
        free(temp);
        return ERROR;
    }//if

    temp -> MAXSTACKSIZE = size;
    temp -> top = temp -> base = temp_array;

    *p_S = temp;

    return OK;
}//init_stack

bool empty_stack(stack * const p_S)
{
    return p_S->top == p_S->base;
}//empty_stack

status push(stack * const p_S,
            generic_ptr const data)
{
    if (num_elements(p_S) == p_S -> MAXSTACKSIZE)
    {
        return ERROR;
    }//if
    
    *p_S->top = data;
    p_S->top++;
    return OK;    

}//push

status pop(stack * const p_S,
            generic_ptr * const p_data)
{
    if (empty_stack(p_S))
    {
        return ERROR;
    }//if
    p_S->top--;
    *p_data = *p_S->top;
    return OK;
}//pop

void destroy_stack(stack * * const p_S,
                    void (*p_func_f)())
{
    for (size_t i=0; i!= (*p_S)->MAXSTACKSIZE; ++i)
    {
        (*p_func_f)(&((*p_S)->base)[i]);
    }//for

    free((*p_S)->base);
    free(*p_S);
    *p_S = NULL;
}//destroy_stack    

#endif
