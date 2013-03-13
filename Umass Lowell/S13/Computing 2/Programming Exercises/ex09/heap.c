//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 9          //
//  heap.c              //
//  2-26-13             //
//**********************//


#ifndef HEAP_C
#define HEAP_C

#include "heap.h"

struct heap {
    size_t HEAP_INCREMENT;
    generic_ptr * base;
    size_t next_element;
    size_t heap_size;
    int (*p_cmp_f)();
};

status init_heap(heap * * const p_H,
                size_t const increment,
                int (*p_cmp_f)())
{
    heap * temp = (heap *) malloc (sizeof(heap));
    if (temp == NULL)
        return ERROR;

    generic_ptr * temp_array = (generic_ptr *) calloc (increment, sizeof(generic_ptr));
    if (temp_array == NULL)
    {
        free(temp);
        return ERROR;
    }//if

    temp -> HEAP_INCREMENT = temp -> heap_size = increment;
    temp -> base = temp_array;
    temp -> next_element = 0;
    temp -> p_cmp_f = p_cmp_f;

    *p_H = temp;

    return OK;
}//init_heap


bool empty_heap(heap * const p_H)
{
    return (p_H -> next_element == 0);
}//empty_heap

void destroy_heap(heap * * const p_H,
                void (*p_func_f)())
{
    for (size_t i=0; i!= (*p_H) -> next_element; ++i)
        (*p_func_f)((*p_H) -> base[i]);

    free((*p_H) -> base);
    free(*p_H);
    *p_H = NULL;
}//destroy_heap

static status parent_index(size_t const index,
                            size_t * const parent)
{
    if (index == 0)
        return ERROR;

    *parent = (index - 1) / 2;
    return OK;
}//parent_index

static size_t first_child_index(size_t const index)
{
    return 2*index + 1;
}//first_child_index

static void swap(heap * const p_H,
                size_t const i_1,
                size_t const i_2)
{
    generic_ptr temp = p_H -> base[i_1];
    p_H -> base[i_1] = p_H -> base[i_2];
    p_H -> base[i_2] = temp;
}//swap

static status increment_heap(heap * const p_H)
{
    size_t new_size = 
        (p_H -> heap_size + p_H -> HEAP_INCREMENT) * sizeof(generic_ptr);
    generic_ptr * newbase = (generic_ptr *) realloc(p_H -> base, new_size);

    if (newbase == NULL)
        return ERROR;

    p_H -> base = newbase;
    p_H -> heap_size += p_H -> HEAP_INCREMENT;
    return OK;
}//increment_heap

static status siftup(heap * const p_H,
                    size_t const index)
{
    if (index == 0)
        return OK;

    {
        size_t parent;
        if (parent_index(index, &parent) == ERROR)
            return ERROR;

        if ((*(p_H -> p_cmp_f))(p_H -> base[index], p_H -> base[parent]) >= 0)
            return OK;

        swap(p_H, index, parent);
        return siftup(p_H, parent);
    }
}

status heap_insert(heap * const p_H,
                    generic_ptr const data)
{
    if (p_H -> next_element == p_H -> heap_size
    &&
    increment_heap(p_H) == ERROR)
         return ERROR;

    p_H -> base[p_H -> next_element] = data;
    if (siftup(p_H, p_H -> next_element) == ERROR)
        return ERROR;

    p_H -> next_element++;
    return OK;
}//heap_insert

static status siftdown (heap * const p_H,
                        size_t const index)
{
    size_t const left_child_index = first_child_index(index);
    if (left_child_index >= p_H -> next_element)
        return OK;
    
    {
        size_t right_child_index = left_child_index + 1;

    /*select the index of the child that is candidate for swapping */
        size_t cmp_target_index = 
            right_child_index == p_H -> next_element ?
            left_child_index :
                (*(p_H -> p_cmp_f))(p_H -> base[left_child_index],
                                 p_H -> base[right_child_index]) > 0?
                right_child_index :
                left_child_index;

        if ((*(p_H -> p_cmp_f))(p_H -> base[index],
                                p_H -> base[cmp_target_index]) > 0)
        {
            swap(p_H, index, cmp_target_index);
            return siftdown(p_H, cmp_target_index);
        }//if
    }//scope
    
    return OK;
}//siftdown

status heap_delete(heap * const p_H,
                    size_t const index,
                    generic_ptr * const p_data)
{
    if (index >= p_H -> next_element)
        return ERROR;

    *p_data = p_H -> base[index];
    p_H -> next_element --;

    p_H -> base[index] = p_H -> base [p_H -> next_element];

    return (siftup(p_H, index) == ERROR ||
            siftdown(p_H, index) == ERROR) ?
                ERROR :
                OK;
}//heap_delete





#endif
