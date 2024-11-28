//
// Created by antekk on 11/28/24.
//
#include "../Headers/kw_t.h"
#include "../Headers/fifo_t.h"
#include "../Headers/load_file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

kw_t** find_keyword(fifo_t* fifo, char** word, int n) {
    kw_t** keywords = malloc(n * sizeof(kw_t*));
    for(int i = 0; i < n; i++) {
        *(keywords + i) = keyWordInit(*(word + i));
    }

//    kw_t* keyword = keyWordInit(word);
//    word_t* wordAndNumber;
    while(fifo->next != NULL) {
        word_t* wordAndNumber = pop(&fifo);
        for(int i = 0; i < n; i++) {
            if (strcmp(*(word + i), wordAndNumber->word) == 0) {
                addNewLineToKw(*(keywords + i), wordAndNumber->line);
            }
        }
    }
    return keywords;
}