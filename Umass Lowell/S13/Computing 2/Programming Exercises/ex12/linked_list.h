//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 10         //
//  linked_list.h       //
//  3-1-13              //
//**********************//

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "globals.h"

typedef struct linked_list_node linked_list_node, *linked_list;

extern status init_linked_list(linked_list * const p_L);

extern bool empty_linked_list(linked_list const L);

extern status linked_list_insert(
    linked_list * const p_L,
    generic_ptr const data,
    linked_list const next);

extern status linked_list_append(
    linked_list * const p_L,
    generic_ptr const data);

extern status linked_list_delete(
    linked_list * const p_L,
    generic_ptr * const p_data,
    linked_list const L);

extern status traverse_linked_list(
    linked_list const L,
    info_ptr const info,
    status (*p_func_f)(),
    ORDER const order);

extern void destroy_linked_list(
    linked_list * const p_L,
    void (*p_func_f)());


#endif //LINKED_LIST_H
