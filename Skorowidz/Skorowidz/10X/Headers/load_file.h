//
// Created by antekk on 11/25/24.
//

#ifndef SKOROWIDZ_JIMP1_LOAD_FILE_H
#define SKOROWIDZ_JIMP1_LOAD_FILE_H

#include <stdio.h>
#include "fifo_t.h"

typedef struct word {
    char* word;
    int line;
} word_t;

fifo_t* get_words(FILE* in);



#endif //SKOROWIDZ_JIMP1_LOAD_FILE_H
