//**********************//
//  Amber Vicki Crosson //
//  91.102              //
//  Exercize 11         //
//  3-01-13             //
//  array_utils.h       //
//**********************//

#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H


#include "int_array.h"

extern status cmp_array(array * const a_1,
                    array * const a_2,
                    int (*p_cmp_f)());

extern status min_array_element (array * const a,
                                size_t const start,
                                size_t const end,
                                size_t * const min_index,
                                int (*p_cmp_f)());

extern status sort_array(array * const a,
                        int (*p_cmp_f)(),
                        SORTING_ALGORITHM const alg);

extern status swap_array_elements(array * const a,
                                size_t const i_1,
                                size_t const i_2);

extern status traverse_array(array * const a,
                            info_ptr const info,
                            status (*p_func_f)());

extern status copy(array * const src,
                    size_t const start,
                    size_t const end,
                    array * const dst,
                    size_t const dst_index);

extern status shuffle_array(array * const a);



#endif //ARRAY_UTILS_H

