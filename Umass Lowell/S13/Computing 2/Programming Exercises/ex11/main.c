//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 11         //
//  3-2-13              //
//  main.c              //
//**********************//

#define _POSIX_C_SOURCE 2

#ifndef MAIN_C
#define MAIN_C

#include "array.h"
#include "array_utils.h"
#include "int_array.h"

#include <stdio.h>
#include <string.h>
#include <getopt.h>

static void destroy_int (int * * p)
{
    free(*p);
    *p = NULL;
}

static void do_nothing(int * * p)
{
    *p = NULL;
}

status parse_algorithm(char * arg,
                        SORTING_ALGORITHM * const alg)
{
    if (strncmp(arg, "merge", 5) == 0)
    {
        *alg = MERGE;
        return OK;
    }//if

    if (strncmp(arg, "selection", 9) == 0)
    {
        *alg = SELECTION;
        return OK;
    }//if

    fprintf(stderr, "Unrecognized algorithm \n");
    return ERROR;
}//parse_algorithm

status parse_args(int argc,
                    char ** argv,
                    bool * const help,
                    SORTING_ALGORITHM * const alg,
                    size_t * const size)
{
    int c;
    *help = false;
    *size = 32;
    *alg = SELECTION;
    
    while ((c = getopt(argc, argv, "a:s:h")) != -1)
    {
        switch (c)
        {
            case 'a':
                if (parse_algorithm(optarg, alg) == ERROR)
                    return ERROR;
                break;
            case 's':
                *size = strtoul(optarg, NULL, 10);
                break;
            case 'h':
                *help = true;
                break;
            default:
                return ERROR;
        }//switch
    }//while

    return OK;
}//parse_args    

void print_usage(FILE * f)
{
    fprintf(f, "Usage: ./ main -a <algorithm> -s <size>\n");
    fprintf(f, "Algorithms:\n");
    fprintf(f, "  merge\n");
    fprintf(f, "  selection\n");
    fprintf(f, "Default algorithm is selection sort.\n");
    fprintf(f, "Default size is 32.\n");
}//print_usage

status init_array_ascending_order(array * const a)
{
    for (size_t i=0, size = array_size(a); i != size; ++i)
        if (set_int(a, i, i) == ERROR)
            return ERROR;

    return OK;
}//init_array_ascending_order

int cmp_int (int * p1, int * p2)
{
    return *p1 - *p2;
}




/////////////////////////////////////////////

int main(int argc, char **argv)
{
    size_t a_size;
    bool print_help;
    array * a;
    array * b;
    SORTING_ALGORITHM alg;

    if (parse_args(argc, argv, &print_help, &alg, &a_size) == ERROR)
        return EXIT_FAILURE;
    
    if (print_help)
        print_usage(stderr);

    if(init_array(&a, a_size) == ERROR)
        return EXIT_FAILURE;

    if (init_array_ascending_order(a) == ERROR)
        return EXIT_FAILURE;

    if (init_array (&b, a_size) == ERROR)
        return EXIT_FAILURE;

    if (copy(a, 0, a_size, b, 0) == ERROR ||
        cmp_array(a, b, cmp_int) != 0)
    {
        return EXIT_FAILURE;
    }

    if (shuffle_array(b) == ERROR)
        return EXIT_FAILURE;

    if (sort_array(b, cmp_int, alg) == ERROR ||
        cmp_array(a, b, cmp_int) != 0)
    {
        return EXIT_FAILURE;
    }//if



    destroy_array(&a, destroy_int);
    destroy_array(&b, do_nothing);

    return EXIT_SUCCESS;
}

#endif

