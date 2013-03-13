//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 11         //
//  globals.h           //
//  3-02-13             //
//**********************//

#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef enum {OK, ERROR} status;
typedef void * generic_ptr;
typedef void* info_ptr;
typedef enum {PREORDER, INORDER, POSTORDER, LEVELORDER} ORDER;
typedef enum { MERGE, SELECTION } SORTING_ALGORITHM;


#endif //GLOBALS_H
