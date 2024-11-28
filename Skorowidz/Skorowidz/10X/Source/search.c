//
// Created by antekk on 11/28/24.
//
#include "../Headers/kw_t.h"
#include "../Headers/fifo_t.h"
#include "../Headers/load_file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

kw_t* find_keyword(fifo_t* fifo, const char* word) {
    kw_t* keyword = keyWordInit(word);
    while(fifo->next != NULL) {
        word_t* wordAndNumber = pop(&fifo);
        if(strcmp(word, wordAndNumber->word) == 0) {
            addNewLineToKw(keyword, wordAndNumber->line);
        }
    }
    return keyword;
}