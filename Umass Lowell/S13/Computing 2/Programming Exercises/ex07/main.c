//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 7          //
//  main.c              //
//  2-19-13             //
//**********************//

#ifndef pfgrcgfyppyf
#define pfgrcgfyppyf

#include "globals.h"
#include "binary_tree.h"

status null_proc(info_ptr info, generic_ptr p)
{
    return p == NULL ? OK : ERROR;
}

void destroy_generic_ptr(generic_ptr * p)
{
    free(*p);
    *p = NULL;
}

int main(int argc, char * * argv)
{
    binary_tree T;

    /* a binary tree is initialized successfully */
    if (init_binary_tree(&T) == ERROR)
        return EXIT_FAILURE;

    /* a binary tree that has just been initialized is empty */
    if (!empty_binary_tree(T))
        return EXIT_FAILURE;

    //an insertion of a single NULL data item into the tree is successful
    if (binary_tree_insert(&T, NULL, NULL, NULL) == ERROR)
        return EXIT_FAILURE;

    //once an element has been inserted, the tre is no longer empty
    if (empty_binary_tree(T))
        return EXIT_FAILURE;

    // a preorder traversal completes without error
    if (traverse_binary_tree(T, NULL, null_proc, PREORDER) == ERROR) 
        return EXIT_FAILURE;

    // an inorder traversal completes without error
    if (traverse_binary_tree(T, NULL, null_proc, INORDER) == ERROR) 
        return EXIT_FAILURE;

    // a postorder traversal completes without error
    if (traverse_binary_tree(T, NULL, null_proc, POSTORDER) == ERROR) 
        return EXIT_FAILURE;

    //a request for a level order traversal returns an error 
    if (traverse_binary_tree(T,NULL,null_proc, LEVELORDER) == OK)
        return EXIT_FAILURE;

    // a request for an unknown order traversal returns an error
    if (traverse_binary_tree(T, NULL, null_proc, 32) == OK) 
        return EXIT_FAILURE;

    destroy_binary_tree(&T, destroy_generic_ptr);

    if (T != NULL)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}


#endif
