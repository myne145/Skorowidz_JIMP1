//
// Created by antekk on 11/24/24.
//
#include <stdlib.h>
#include <stdio.h>

#include "../Headers/fifo_t.h"

fifo_t* init(void* value) {
    fifo_t* fifo = malloc(sizeof(fifo_t));
    if(fifo == NULL) {
        fprintf(stderr, "Nie udało się przypisać pamięci dla elementu!");
        return NULL;
    }

    fifo->currentValue = value;
    fifo->next = malloc(sizeof(fifo_t));
    return fifo;
}

int length(fifo_t* fifo) {
    int n = 0;
    while(fifo->next != NULL) {
        fifo = fifo->next;
        n++;
    }
    return n;
}


void push(fifo_t* fifo, void* element) {
    //znajdujemy ostatni element kolejki
    while(fifo->next != NULL) {
        fifo = fifo->next;
    }

    fifo->next = malloc(sizeof(fifo_t));
    fifo->next->currentValue = element;
}
