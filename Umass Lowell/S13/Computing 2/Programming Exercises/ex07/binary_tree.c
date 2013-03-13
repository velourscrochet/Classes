//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 7          //
//  binary_tree.c       //
//  2-19-13             //
//**********************//


#ifndef aoeudtnthdiueuihdt
#define aoeudtnthdiueuihdt

#include "globals.h"
#include "binary_tree.h"

struct binary_tree_node {
    generic_ptr data_pointer;
    binary_tree left;
    binary_tree right;
};

static status allocate_binary_tree_node(
    binary_tree * const p_T,
    generic_ptr const data)
{
    binary_tree T = (binary_tree) malloc(sizeof(binary_tree_node));

    if (T == NULL)
        return ERROR;

    *p_T = T;
    ((T)->data_pointer) = data;
    ((T)->left) = NULL;
    ((T)->right) = NULL;
    return OK;
}

bool empty_binary_tree(binary_tree const T)
{
    return T == NULL;
}

void free_binary_tree_node(p_T)
binary_tree *p_T;
{
    /*
    *   Reclaim the space used by the tree_node}
    */
    free(*p_T);
    *p_T = NULL;
}

status init_binary_tree(binary_tree * const p_T)
{
    *p_T = NULL;
    return OK;   
}

status binary_tree_insert(
    binary_tree * const p_T,
    generic_ptr const data,
    binary_tree const left,
    binary_tree const right)
{
    //Allocate a new mode and make that the root of a tree

    if (empty_binary_tree(*p_T) == false)
        return ERROR;

    if (allocate_binary_tree_node(p_T, data) == ERROR)
        return ERROR;

    ((*p_T)->left) = left;
    ((*p_T)->right) = right;
    return OK;    
}

static status traverse_preorder(
    binary_tree const T,
    info_ptr const info,
    status (*p_func_f)())
{
    if (T == NULL)
        return OK;

    return (
            (*p_func_f)(info, T->data_pointer) == OK
            &&
            traverse_preorder(T->left, info, p_func_f) == OK
            &&
            traverse_preorder(T->right, info, p_func_f) == OK)?
            OK : ERROR;
    
}

static status traverse_inorder(
    binary_tree const T,
    info_ptr const info,
    status (*p_func_f)())
{
    if (T == NULL)
    {
        return OK;
    }

    return (traverse_inorder(T->left, info, p_func_f) == OK 
            &&
            (*p_func_f)(info, T->data_pointer) == OK
            &&
            traverse_inorder(T->right, info, p_func_f) == OK)?
            OK : ERROR;
}


static status traverse_postorder(
    binary_tree const T,
    info_ptr const info,
    status (*p_func_f)())
{
    if (T == NULL)
        return OK;

    return (traverse_postorder(T->left, info, p_func_f) == OK
            &&
            traverse_postorder(T->right, info, p_func_f) == OK
            &&
            (*p_func_f)(info, T->data_pointer) == OK)?
            OK : ERROR;


}


status traverse_binary_tree(
    binary_tree const T,
    info_ptr const info,
    status (*p_func_f)(),
    ORDER const order)
{
    switch (order) {
        case PREORDER:
            return traverse_preorder(T, info, p_func_f);
        case INORDER:
            return traverse_inorder(T, info, p_func_f);
        case POSTORDER:
            return traverse_postorder(T, info, p_func_f);
        case LEVELORDER:
            return ERROR;
        default:
            return ERROR;
    }
}

void destroy_binary_tree(
    binary_tree * const p_T,
    void (*p_func_f)())
{
    if (*p_T != NULL)
    {
        destroy_binary_tree(&((*p_T)->left), p_func_f);
        destroy_binary_tree(&((*p_T)->right), p_func_f);
        (*p_func_f)(&((*p_T)->data_pointer));
        free_binary_tree_node(p_T);
    }
}


#endif
