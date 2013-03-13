//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 6          //
//  main.c              //
//  2-12-13             //
//**********************//

#ifndef H785212357984
#define H785212357984

#include "globals.h"
#include "stack.h"
#include "stack_utils.h"

#include <stddef.h>
#include <stdlib.h>

void destroy_generic_ptr(generic_ptr * p)
{
    free(*p);
    *p = NULL;
}//destroy_generic_ptr


int main(int argc, char * * argv)
{
    size_t const stack_size = 10;
    stack * p_S;

    /* a stack is initialized successfully */
    if (init_stack(&p_S, stack_size) == ERROR)
    {
        return EXIT_FAILURE;
    }//if

    /* a newly created stack is empty */
   if (!empty_stack(*p_S))
   {
        return EXIT_FAILURE;
    }//if

    /*pushing stack_size elements onto a stack succeeds */
    for (size_t i=0; i!= stack_size; ++i)
    {
        generic_ptr p=NULL;
        if (push (p_S, p) == ERROR)
        {
        return EXIT_FAILURE;
        }//if
    }//for

    /* pushing the stack_size + 1th element fails */
    generic_ptr p;
    if (push(p_S, p) != ERROR)
    {
        return EXIT_FAILURE;
    }//if

    /* a stack with elements pushed on is not empty */
    if (empty_stack ( *p_S))
    {
        return EXIT_FAILURE;
    }//if

    /* stack_size pops from a full stack succeed */
    for(size_t i=0; i!=stack_size; ++i)
    {
        generic_ptr p;
        if (pop(p_S, &p) == ERROR)
        {
            return EXIT_FAILURE;
        }//if
    }//for

    /* accessing the top element of an empty stack gives an error */
//    generic_ptr p;
    if (top(p_S, &p) != ERROR)      //I'm a bit uncertain about why this is !=
    {
        return EXIT_FAILURE;
    }//if

    for (size_t i=0; i!=stack_size; ++i)
    {
    //    generic_ptr p=NULL;
        if (push(p_S, p) == ERROR)
        {
            return EXIT_FAILURE;
        }//if
    }//for

    /*accessing the top element of a non-empty stack succeeds */
   // generic_ptr p;
    if (top(p_S, &p) == ERROR) 
    {
        return EXIT_FAILURE;
    }//if

    destroy_stack(&p_S, destroy_generic_ptr);
    
    /*the stack pointer is NULL after the stack is destroyed */
    if (p_S != NULL)
    {
        return EXIT_FAILURE;
    }//if    

    return EXIT_SUCCESS;
}



#endif
