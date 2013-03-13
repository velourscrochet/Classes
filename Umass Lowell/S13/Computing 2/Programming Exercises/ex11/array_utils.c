//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 11         //
//  3-02-13             //
//  array_utils.c       //
//**********************//

#ifndef ARRAY_UTILS_C
#define ARRAY_UTILS_C

#include "globals.h"
#include "array.h"
#include "array_utils.h"
#include "int_array.h"

status traverse_array(array * const a,
                    info_ptr const info,
                    status (*p_func_f)())
{
    for (size_t i=0, size = array_size(a); i != size; ++i)
    {

        generic_ptr p;
	if (get(a, i, &p) == ERROR)
		return ERROR;

        if ((*p_func_f)(info, p) == ERROR)
            return ERROR;
    }

    return OK;
}

status cmp_array(array * const a_1,
                array * const a_2,
                int (*p_cmp_f)())
{
    int cmp_result = 0;
    size_t size_1 = array_size(a_1),
            size_2 = array_size(a_2);

    for (size_t i=0;
        i != size_1 && i != size_2 && cmp_result == 0;
        ++i)
    {
        generic_ptr p1, p2;
        if (get(a_1, i, &p1) == ERROR ||
            get(a_2, i, &p2) == ERROR)
        { return ERROR; }
        
        cmp_result = (*p_cmp_f)(p1, p2);
    }
    return cmp_result == 0 ?
            size_1 - size_2 :
            cmp_result;
}

static status min_array_element_internal(array * const a,
                                        size_t const start,
                                        size_t const end,
                                        size_t * const min_index,
                                        int (*p_cmp_f)())
{
    if (start == end)
        return OK;
    else
    {
        generic_ptr p_start, p_min;
        if (get (a, start, &p_start) == ERROR ||
            get(a, *min_index, &p_min) == ERROR)
            { return ERROR; }

        if ((*p_cmp_f)(p_start, p_min) < 0 )
            *min_index = start;
        return min_array_element_internal(a, start + 1, end, min_index, p_cmp_f);
    }
}

status min_array_element(array * const a,
                        size_t const start,
                        size_t const end,
                        size_t * const min_index,
                        int (*p_cmp_f)())
{
    if (start == end)
        return ERROR;
    else
    {
        *min_index = start;
        return min_array_element_internal(a, start+1, end, min_index, p_cmp_f);
    }
}

status swap_array_elements(array * const a,
                            size_t const i_1,
                            size_t const i_2)
{
    generic_ptr p_1, p_2;
    if (get(a, i_1, &p_1) == ERROR ||
        get(a, i_2, &p_2) == ERROR)
        { return ERROR; }
    if (set (a, i_1, p_2) == ERROR ||
        set (a, i_2, p_1) == ERROR)
        return ERROR;

    return OK;
}//swap_array_elements

static status selection_sort(array * const a,
                            size_t const start,
                            size_t const end,
                            int (*p_cmp_f)())
{
    if (start == end)
        return OK;
    else
    {
        size_t min_index;
        if (min_array_element(a, start, end, &min_index, p_cmp_f) == ERROR)
            return ERROR;

        swap_array_elements(a, min_index, start);
        return selection_sort(a, start + 1, end, p_cmp_f);
    }
}//selection_sort


status copy(array * const src,
                    size_t const start,
                    size_t const end,
                    array * const dst,
                    size_t const dst_index)
{
    for (size_t i=start, j = dst_index, size = array_size(dst);
            i != end && j != size;
            ++i, ++j)
    {
        generic_ptr p;
        if (get(src, i, &p) == ERROR
                ||
                set(dst, j, p) == ERROR)
        {return ERROR;}
    }//for

    return OK;
}//copy
    
status shuffle_array(array * const a)
{
    for (size_t i=0, size = array_size(a); i != size; ++i)
    {
        size_t j = i + rand() / (RAND_MAX / (size - i) + 1);
        if (swap_array_elements(a, i, j) == ERROR)
            return ERROR;
    }//for

    return OK;
}//shuffle_array

status merge(array * const a,
            size_t const start_left,
            size_t const end_left,
            size_t const start_right,
            size_t const end_right,
            array * const scratch,
            size_t const scratch_start,
            int (*p_cmp_f)())
{
    if (start_left == end_left)
        return copy(a, start_right, end_right, scratch, scratch_start);
    if (start_right == end_right)
        return copy(a, start_left, end_left, scratch, scratch_start);

    {
        generic_ptr p_1, p_2;

        if (get(a, start_left, &p_1) == ERROR ||
            get(a, start_right, &p_2) == ERROR)
        {
            return ERROR;
        }//if

        if ((*p_cmp_f)(p_1, p_2) < 0)
        {
            return set(scratch, scratch_start, p_1) == ERROR ?
                ERROR :
                merge(  a,
                        start_left + 1,
                        end_left,
                        start_right,
                        end_right,
                        scratch,
                        scratch_start + 1,
                        p_cmp_f);
        } else
        {
            return set(scratch, scratch_start, p_2) == ERROR ?
                ERROR :
                merge(  a,
                        start_left,
                        end_left,
                        start_right + 1,
                        end_right,
                        scratch,
                        scratch_start + 1,
                        p_cmp_f);
        }//else
    }//scope
}//merge

status merge_sort(array * const a,
                size_t const start,
                size_t const end,
                array * const scratch,
                int (*p_cmp_f)())
{
    if (start == end || start == end - 1)
        return OK;
    else
    {
        size_t middle = (end - start) / 2 + start;

        if (merge_sort(a, start, middle, scratch, p_cmp_f) == ERROR ||
            merge_sort(a, middle, end, scratch, p_cmp_f) == ERROR)
        {
            return ERROR;
        }//if

        if (merge(a,
                start,
                middle,
                middle,
                end,
                scratch,
                start,
                p_cmp_f) == ERROR)
        {
            return ERROR;
        }//if

    return copy(scratch, start, end, a, start);
    }//else
}//merge_sort

static void do_nothing(generic_ptr * p)
{
    *p = NULL;
}

status sort_array(array * const a,
                int (*p_cmp_f)(),
                SORTING_ALGORITHM const alg)
{
    switch (alg)
    {
        case MERGE:
        {
            array * scratch;
            status rc;

            if (init_array(&scratch, array_size(a)) == ERROR)
                return ERROR;

            rc = merge_sort(a, 0, array_size(a), scratch, p_cmp_f);
            destroy_array(&scratch, do_nothing);

            return rc;
        }//case MERGE

        case SELECTION :
            return selection_sort(a, 0, array_size(a), p_cmp_f);

        default:
            return ERROR;
    }//switch
}//sort_array




#endif
