//
// Created by antekk on 11/28/24.
//

#include "fifo_t.h"

#ifndef SKOROWIDZ_JIMP1_SORT_H
#define SKOROWIDZ_JIMP1_SORT_H

/**
 * sortuje fifo bazując na ilośći wystąpień słowa tylko dla kw_t
 * @param que fifo
 * @return fifo posortowane
 */
fifo_t* sortFifo(fifo_t* que);
fifo_t* listToFifo(kw_t** list,int size);


#endif //SKOROWIDZ_JIMP1_SORT_H
