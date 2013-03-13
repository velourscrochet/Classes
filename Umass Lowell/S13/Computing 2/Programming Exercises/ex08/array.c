//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 8          //
//  2-21-13             //
//  array.c             //
//**********************//

#include "globals.h"
#include "array.h"
/*#ifndef stddef
 #define stddef*/
 #include <stddef.h> //size_t
/* #endif
#ifndef stdlib
 #define stdlib*/
  #include <stdlib.h> //free()
//#endif

struct array                                    //defines the 'array' struct
{
    size_t size;
    generic_ptr * a;
};  //struct array

//init_array : ptr to a ptr to an array, constant size -> status (ERROR = 1, OK = 0)
status init_array(array * * a,
                size_t const size)  
{
    array * temp = malloc (sizeof(array));      //initializes temp as a ptr to an array

    if (temp == NULL)                           //if temp is NULL, Error
    {
        return ERROR;
    }   //if

    generic_ptr * temp_array = (generic_ptr *)  //initializes temp_array as a ptr to a generic_ptr
         calloc(size, sizeof(generic_ptr));

    if (temp_array == NULL)                     //if temp_array is NULL, Error
    {
        free(temp);
        return ERROR;
    }   //if

    for (size_t i=0; i != size; ++i)            //Cause temp_array to be NULL for all i in temp_array
    {
        temp_array[i] = NULL;
    }   //for

    temp -> a=temp_array;
    temp -> size = size;
    *a = temp;

    return OK;                                  //Else, OK
}   //definition of init_array

//set : ptr to array, const size, const generic_ptr -> status (OK = 0, ERROR = 1)
status set(array * a, 
            size_t const index,
            generic_ptr const val)
{
    if (index >= a->size)                       //if your index is invalid, Error
    {
        return ERROR;
    }//if
    a->a[index]=val;                            //otherwise, make a[index] the given value
    return OK;                                  //and return OK
}//definition of set

//get : ptr to an array, const size_t, const ptr to generic_ptr -> status (OK = 0, ERROR = 1)
status get(array * a,
		size_t const index,
		generic_ptr * const val)
{
    if (index >= a->size)                       //if index invalid, Error
    {
        return ERROR;
    }//if

    *val = a->a[index];                         //otherwise, grab the value of a[index]
    return OK;                                  //and return OK
}//definition of get

//destroy_array : ptr to ptr to array, ptr to a function -> nothing
void destroy_array(array * * a,
                    void (*p_func_f)())
{
    for (size_t i=0; i != (*a)->size; ++i)      //for every index value
    {
        (*p_func_f)(&((*a)->a)[i]);             //??
    }//for

    free ((*a)->a);                             
    free(*a);
    *a = NULL;                                  //reset the ptr to a to be NULL
}//definition of destroy_array

size_t array_size(array * a)
{
    return a->size;
}

