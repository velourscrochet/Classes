#ifndef a1234567890
#define a1234567890

#include "globals.h"
#include "array.h"
#include <stdlib.h>

//destroy_generic_ptr : ptr to generic_ptr -> nothing
void destroy_generic_ptr(generic_ptr * p)
{
    free(*p);                                   //frees memory from ptr to p
    *p=NULL;                                    //and resets it to NULL
}//definition destroy_generic_ptr

//main -> int, ptr to ptr to char -> int
int main(int argc, char **argv)
{
    size_t const a_size = 3;                    //defines a_size
    array * a;                                  //declares a
    
    if (init_array(&a, a_size) == ERROR)        
    {
        return ERROR;
    }//if

    if (set(a, 3, NULL) != ERROR) 
    {
        return ERROR;
    }//if

    if (set(a, 2, NULL)==ERROR)
    {
        return ERROR;
    }//if	
    
    generic_ptr p;                              //declares p
    
    if (get(a, 3, &p) != ERROR) 
    {
        return ERROR;
    }//if

    if (get(a, 2, &p) == ERROR) 
    {
        return ERROR;
    }//if

    destroy_array(&a, destroy_generic_ptr);     //remove the generic_ptr and the array in use

    if (a != NULL) 
    {
        return ERROR;
    }//if

    return OK;                                  //else, OK
}//if


#endif
