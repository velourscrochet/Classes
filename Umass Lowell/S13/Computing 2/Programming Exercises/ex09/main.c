//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 9          //
//  main.c              //
//  2-26-13             //
//**********************//

#ifndef MAIN_C
#define MAIN_C

#include "heap.h"
#include "int_heap.h"

int cmp_int(int * l, int * r)
{
    return *l - *r;
}

void destroy_int(int * * p_i)
{
    free(*p_i);
    *p_i = NULL;
}


/////////////////////////MAIN PROCEDURE//////////////////////
int main(int argc, char * * argv)
{
    heap * p_H;

/* a new heap is empty */
    if (init_heap(&p_H, 256, cmp_int) == ERROR || !empty_heap(p_H))
        return EXIT_FAILURE;

/* a heap with one element is not empty */
    if (heap_insert_int(p_H, 2) == ERROR || empty_heap(p_H))
        return EXIT_FAILURE;

/* the minimum element is 1 */
    {
        int res;
        if (heap_insert_int(p_H, 1) == ERROR ||
            heap_insert_int(p_H, 5) == ERROR ||
            heap_delete_int(p_H, 0, &res) == ERROR ||
            res != 1)
        {
            return EXIT_FAILURE;
        }//if
    }//scope

/* there is no element at index 2 */
    {
        int res;
        if (heap_delete_int(p_H, 2, &res) == OK)
            return EXIT_FAILURE;
    }//scope
    
/* The element on the second level is 5 */
    {
        int res;
        if (heap_delete_int(p_H, 1, &res) == ERROR || res != 5)
            return EXIT_FAILURE;
    }//scope

/* the remaining element is 2 */
    {
        int res;
        if (heap_delete_int(p_H, 0, &res) == ERROR || res != 2)
            return EXIT_FAILURE;
    }//scope

/* removing an element from an empty heap yeilds an error */
    {
        int res;
        if (heap_delete_int(p_H, 0, &res) == OK)
            return EXIT_FAILURE;
    }//scope






    destroy_heap(&p_H, destroy_int);

/* after destruction, the heap is NULL?*/
    if (p_H != NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}




#endif

