//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 7          //
//  globals.h           //
//  2-19-13             //
//**********************//

//#ifndef H0f2a6614_6102_11e2_be81_005056963a9a
//#define H0f2a6614_6102_11e2_be81_005056963a9a
#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdbool.h>
#include <stddef.h>
//#ifndef stdlib
// #define stdlib
	#include <stdlib.h>
//#endif

typedef enum {OK, ERROR} status;
typedef void * generic_ptr;
typedef void* info_ptr;
typedef enum {PREORDER, INORDER, POSTORDER, LEVELORDER} ORDER;

#endif //GLOBALS_H
