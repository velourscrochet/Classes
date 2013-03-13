//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 10         //
//  main.c	        //
//  3-1-13              //
//**********************//

#ifndef MAIN_C
#define MAIN_C

#include "linked_list.h"

void destroy_generic_ptr(generic_ptr * p)
{
    free(*p);
    *p = NULL;

}//destroy_generic_ptr

status null_proc(info_ptr info, generic_ptr p)
{
    return p == NULL ? OK : ERROR;
}


int main(int argc, char * * argv)
{
    linked_list L;

    if (init_linked_list(&L) == ERROR &&
        !empty_linked_list(L))
    {
        return EXIT_FAILURE;
    }

    if (linked_list_insert(&L, NULL, NULL) == ERROR || empty_linked_list(L))
        return EXIT_FAILURE;

    if (linked_list_insert(&L, NULL, L) == ERROR)
        return EXIT_FAILURE;

    {
        generic_ptr p;
        if (linked_list_delete(&L, &p, L) == ERROR || p!=NULL)
            return EXIT_FAILURE;
    }//scope

    {
        generic_ptr p;
        if (linked_list_delete(&L, &p, L) == ERROR)
            return EXIT_FAILURE;
    }//scope

    if (!empty_linked_list(L))
        return EXIT_FAILURE;

    if (linked_list_append(&L, NULL) == ERROR || empty_linked_list(L))
        return EXIT_SUCCESS;

    if (linked_list_append(&L, NULL) == ERROR || empty_linked_list(L))
        return EXIT_SUCCESS;

    {
        generic_ptr p;
        if (linked_list_delete(&L, &p, NULL) == OK)
            return EXIT_FAILURE;
    }//scope

    {
        generic_ptr p;
        linked_list temp;

        if(init_linked_list (&temp) == ERROR ||
            linked_list_insert(&temp, NULL, temp) == ERROR)
        {
            return EXIT_FAILURE;
        }//if

        if(linked_list_delete(&L, &p,temp) == OK)
            return EXIT_FAILURE;

        destroy_linked_list(&temp, destroy_generic_ptr);
    }//scope

    {
        generic_ptr p;
        if (linked_list_delete(&L, &p, L) == ERROR ||
            linked_list_delete(&L, &p, L) == ERROR)
        {
            return EXIT_FAILURE;
        }//if
    }//scope

    {
        generic_ptr p;
        if (linked_list_delete(&L, &p, L) == OK)
            return EXIT_FAILURE;
    }//scope

    {
        generic_ptr p;
        linked_list temp;

        if (init_linked_list(&temp) == ERROR ||
            linked_list_insert(&temp, NULL, temp) == ERROR)
        {
            return EXIT_FAILURE;
        }//if

        if (linked_list_delete(&L, &p, temp) == OK)
            return EXIT_FAILURE;

        destroy_linked_list(&temp, destroy_generic_ptr);
    }//scope

    if(linked_list_insert(&L, NULL, L) == ERROR ||
        linked_list_append(&L, NULL) == ERROR)
    {
        return EXIT_FAILURE;
    }//if

    if (traverse_linked_list(L, NULL, null_proc, PREORDER) == ERROR)
        return EXIT_FAILURE;

    if (traverse_linked_list(L, NULL, null_proc, INORDER) == OK)
        return EXIT_FAILURE;

    if (traverse_linked_list(L, NULL, null_proc, POSTORDER) == ERROR)
        return EXIT_FAILURE;

    if (traverse_linked_list(L, NULL, null_proc, LEVELORDER) == OK)
        return EXIT_FAILURE;

    if (traverse_linked_list(L, NULL, null_proc, 32) == OK)
        return EXIT_FAILURE;




    destroy_linked_list(&L, destroy_generic_ptr);

    if (L != NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}//main

#endif //MAIN_C
