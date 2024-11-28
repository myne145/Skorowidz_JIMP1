//
// Created by antekk on 11/25/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/fifo_t.h"
#include "../Headers/kw_t.h"

#define BUFSIZE 8192 //ilość bajtów na linijkę

fifo_t get_words(FILE* in) {
    char* buffer = malloc(BUFSIZE * sizeof(char ));

    fifo_t* fifo = init("A");


    int index = 0;
    char c;
    while((c = fgetc(in)) != EOF) {
        if(c == ' ' || c == '\n') {
            push(fifo, buffer);
            buffer = calloc(sizeof(char) * BUFSIZE, sizeof(char) * BUFSIZE);
            index = 0;
            continue;
        }
        buffer[index] = c;
        index++;
    }

    print_fifo(fifo);


}