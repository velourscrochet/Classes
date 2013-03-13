//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 10         //
//  linked_list.c       //
//  3-1-13              //
//**********************//

#ifndef LINKED_LIST_C
#define LINKED_LIST_C

#include "linked_list.h"

struct linked_list_node
    {
    generic_ptr data_pointer;
    linked_list next;
    }; //struct

static status allocate_linked_list_node(
    linked_list * const p_L,
    generic_ptr const data)
{
    linked_list L = (linked_list) malloc(sizeof(linked_list_node));

    if (L == NULL)
        return ERROR;

    *p_L = L;
    ((L)->data_pointer) = data;
    ((L)->next) = NULL;
    return OK;

}//allocate_linked_list_node

static void free_linked_list_node(linked_list * p_L)
{
    free(*p_L);
    *p_L = NULL;

}//free_linked_list_node

status init_linked_list(linked_list * const p_L)
{
    *p_L = NULL;
    return OK;

}//init_linked_list

bool empty_linked_list(linked_list const L)
{
    return L == NULL;

}//empty_linked_list

void destroy_linked_list(
    linked_list * const p_L,
    void (*p_func_f)())
{
    if (*p_L != NULL)
    {
        destroy_linked_list(&((*p_L)->next), p_func_f);
        (*p_func_f)(&((*p_L)->data_pointer));
        free_linked_list_node(p_L);
    }//if
}//destroy_linked_list

status linked_list_insert(
    linked_list * const p_L,
    generic_ptr const data,
    linked_list const next)
{
    linked_list temp;

    if (allocate_linked_list_node(&temp, data) == ERROR)
        return ERROR;

    temp -> next = next;

    *p_L = temp;

    return OK;
}//linked_list_insert

status linked_list_delete(
    linked_list * const p_L,
    generic_ptr * const p_data,
    linked_list const L)
{
    if (L == NULL)
        return ERROR;
    else
    {
        linked_list * temp;
        for (temp = p_L; *temp != NULL && *temp != L; temp = &((*temp)->next));
        if (*temp == NULL)
            return ERROR;
        else
        {
            linked_list next = L -> next;
            *p_data = L -> data_pointer;
            free_linked_list_node(temp);
            *temp = next;
            return OK;
        }//else
    }//else
}//linked_list_delete

status linked_list_append(
    linked_list * const p_L,
    generic_ptr const data)
{
    if (*p_L == NULL)
        return linked_list_insert(p_L, data, NULL);
    else
    {
        linked_list * last;
        for (last = p_L;
            *last != NULL;
            last = &((*last)->next));
        return linked_list_insert(last,data,NULL);
    }//else
}//linked_list_append

static status traverse_preorder(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)())
{
    if (L == NULL)
        return OK;

    return ((*p_func_f)(info, L->data_pointer) == OK
                &&
            traverse_preorder(L->next, info, p_func_f) == OK) ?
            OK :
            ERROR;
}//traverse_preorder

static status traverse_postorder(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)())
{
    if (L == NULL)
        return OK;

    return ERROR;
}//traverse_postorder

status traverse_linked_list(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)(),
    ORDER const order)
{
    switch (order) {
        case PREORDER:
            return traverse_preorder(L, info, p_func_f);
        case INORDER:
            return ERROR;
        case POSTORDER:
            return traverse_postorder(L, info, p_func_f);
        case LEVELORDER:
            return ERROR;
        default:
            return ERROR;
    }//switch
}//traverse_linked_list



#endif //LINKED_LIST_C
