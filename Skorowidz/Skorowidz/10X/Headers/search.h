//
// Created by antekk on 11/28/24.
//

#ifndef SKOROWIDZ_JIMP1_SEARCH_H
#define SKOROWIDZ_JIMP1_SEARCH_H

#include "fifo_t.h"
#include "kw_t.h"

/**
 * szuka słowa w kolejce
 * @param fifo kolejka w której szukamy słowa
 * @param keyword szukane słowo
 * @return struktura keyword z informacjami o słowie
 */
kw_t* find_keyword(fifo_t* fifo, const char* word);



#endif //SKOROWIDZ_JIMP1_SEARCH_H
