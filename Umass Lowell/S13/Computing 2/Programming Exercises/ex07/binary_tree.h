//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 7          //
//  binary_tree.h       //
//  2-19-13             //
//**********************//

#ifndef ansotmhpyuidhtmntt
#define ansotmhpyuidhtmntt

#include "globals.h"

typedef struct binary_tree_node binary_tree_node, *binary_tree;

extern status init_binary_tree(binary_tree * const p_T);

extern bool empty_binary_tree(binary_tree const T);

extern status binary_tree_insert(
    binary_tree * const p_T,
    generic_ptr const data,
    binary_tree const left,
    binary_tree const right);

extern status traverse_binary_tree(
    binary_tree const T,
    info_ptr const info,
    status (*p_func_f)(),
    ORDER const order);

extern void destroy_binary_tree(
    binary_tree * const p_T,
    void (*p_func_f)());

#endif
