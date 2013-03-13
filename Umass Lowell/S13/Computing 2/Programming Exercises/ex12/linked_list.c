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

status linked_list_insert(
    linked_list * const p_L,
    generic_ptr const data,
    linked_list const next)
{
    linked_list temp;

    if (allocate_linked_list_node(&temp, data) == ERROR)
        return ERROR;

    if (next == NULL)
    {
        temp->next = temp;
        *p_L = temp;
    }//if
    else
    {
        temp->next = next -> next;
        next->next = temp;
        *p_L = next;
    }//else    

    return OK;

}

status linked_list_delete(
    linked_list * const p_L,
    generic_ptr * const p_data,
    linked_list const L)
{
    if (L == NULL || *p_L == NULL)
        return ERROR;
    else
    {
        linked_list temp;
        for (temp = (*p_L)->next;
            temp != *p_L && temp->next != L;
            temp = temp->next);
        if (temp->next != L)
            return ERROR;
        else
        {
            linked_list next = L -> next;
            *p_data = L -> data_pointer;
            *p_L = *p_L == L ? temp : *p_L;
            
            if (L -> next == L)
                free_linked_list_node(p_L);
            else
            {
                free_linked_list_node(&(temp->next));
                temp->next = next;
            }//else

        return OK;
        }//else

    }//else

}//linked_list_delete

status linked_list_append(
    linked_list * const p_L,
    generic_ptr const data)
{
    if (linked_list_insert(p_L, data, *p_L) == ERROR)
        return ERROR;

    *p_L = (*p_L) -> next;
    return OK;

}//linked_list_append

static status traverse_preorder(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)(),
    linked_list const last)
{
    if (L == last 
        &&
        (*p_func_f)(info, L->data_pointer) == OK)
    {
        return OK;
    }//if

    return ((*p_func_f)(info, L->data_pointer) == OK
            &&
            traverse_preorder(L->next, info, p_func_f, last) == OK) ?
        OK :
        ERROR;

}//traverse_preorder

static status traverse_postorder(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)(),
    linked_list const last)
{
    if (L == last 
        &&
        (*p_func_f)(info, L->data_pointer) == OK)
    {
        return OK;
    }//if

    return (traverse_postorder(L->next, info, p_func_f, last) == OK
            &&
            (*p_func_f)(info, L->data_pointer) == OK) ?
            OK :
            ERROR;

}//traverse_postorder

status traverse_linked_list(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)(),
    ORDER const order)
{
    switch (order)
    {
        case PREORDER:
            return L == NULL ? 
            OK : 
            traverse_preorder(L->next, info, p_func_f, L);
        case INORDER:
            return ERROR;
        case POSTORDER:
            return L == NULL ?
                    OK :
                    traverse_postorder(L->next, info, p_func_f, L);
        case LEVELORDER:
            return ERROR;
        default:
            return ERROR;
    }//switch

}//traverse_linked_list

void destroy_linked_list_internal(linked_list * const p_L,
                                    void (*p_func_f)(),
                                    linked_list const last)
{
    if ((*p_L)->next != last)
    {
        destroy_linked_list_internal(&((*p_L)->next), p_func_f, last);
    }//if
    if (*p_L != last)
    {
        (*p_func_f)(&((*p_L)->data_pointer));
        free_linked_list_node(p_L);
    }//if
}//destroy_linked_list_internal

void destroy_linked_list(
    linked_list * const p_L,
    void (*p_func_f)())
{
    if(*p_L != NULL)
    {
        destroy_linked_list_internal(&((*p_L)->next), p_func_f, *p_L);
        (*p_func_f)(&((*p_L)->data_pointer));
        free_linked_list_node(p_L);
    }//if

}//destroy_linked_list

#endif //LINKED_LIST_C
