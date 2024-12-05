//
// Created by antekk on 11/25/24.
//
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/fifo_t.h"
#include "../Headers/load_file.h"

fifo_t* get_words(FILE* in) {
    char* buffer = malloc(WORD_LENGTH * sizeof(char ));

    fifo_t* fifo = init("");


    int index = 0;
    char c;
    int line = 1;
    while((c = fgetc(in)) != EOF) {
        if(c == ' ' || c == '\n' || c == ',' || c == '.') {
            word_t* word1 = malloc(sizeof(word_t*));
            word1->line = line;
            word1->word = buffer;

            push(fifo, word1);

            if(c == '\n')
                line++;

            buffer = calloc(WORD_LENGTH, sizeof(char));
            index = 0;
            continue;
        }

        if(index >= WORD_LENGTH) {
            fprintf(stderr, "Nie można dodać słowa - zawiera więcej niż %d znaków!\n", WORD_LENGTH);
            continue;
        }
        buffer[index] = c;
        index++;
    }

    free(buffer);
    return fifo;
}