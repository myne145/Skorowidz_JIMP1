//
// Created by antekk on 11/24/24.
//
#include <stdlib.h>
#include <stdio.h>

#include "../Headers/fifo_t.h"
#include "../Headers/load_file.h"

#define QUEUE_SIZE 5000 //maksymalna ilość elementów w kolejce

fifo_t* init(void* value) {
    fifo_t* fifo = malloc(sizeof(fifo_t));
    if(fifo == NULL) {
        fprintf(stderr, "Nie udało się przypisać pamięci dla elementu %p!\n", value);
        return NULL;
    }

    fifo->currentValue = value;
    fifo->next = malloc(sizeof(fifo_t));
    return fifo;
}

int length(fifo_t* fifo) {
    if(fifo == NULL) {
        fprintf(stderr, "Nie można sprawdzić długości - niezaincjalizowana zmienna fifo.\n");
        return 0;
    }
    int n = 0;
    while(fifo->next != NULL) {
        fifo = fifo->next;
        n++;
    }
    return n;
}


int push(fifo_t* fifo, void* element) {
    if(length(fifo) >= QUEUE_SIZE) {
        fprintf(stderr, "Nie można dodać wartości %p - "
                        "przekroczono maksymalną wielkośc kolejki.\n", element);
        return 0;
    } else if(fifo == NULL) {
        fprintf(stderr, "Nie można dodać wartości %p - "
                        "niezainicjalizowana zmienna fifo.\n", element);
        return 0;
    }

    //znajdujemy ostatni element kolejki
    while(fifo->next != NULL) {
        fifo = fifo->next;
    }

    fifo->next = malloc(sizeof(fifo_t*));
    fifo->currentValue = element;
    return 1;
}

void* pop(fifo_t* *fifo) {
    if(fifo == NULL) {
        fprintf(stderr, "Nie można usunąć wartości - niezaincjalizowana zmienna fifo.\n");
        return NULL;
    }

    fifo_t* temp = *fifo;
    void* val = temp->currentValue;

    if(temp->next == NULL) {
        fprintf(stderr, "Nie można usunąć wartości - wyjście po za granicę listy.\n");
        return NULL;
    }

    *fifo = temp->next;
    free(temp);

    return val;
}

void* find(fifo_t* fifo, void* pattern) {
    if(fifo == NULL) {
        fprintf(stderr, "Nie można znaleźć wartości - niezaincjalizowana zmienna fifo.\n");
        return NULL;
    }

    while(fifo->next != NULL) {
        if(fifo->currentValue == pattern) {
            return fifo->currentValue;
        }

        fifo = fifo->next;
    }
    return NULL;
}

void print_fifo(fifo_t* fifo) {
    while(fifo->next != NULL) {
        word_t* s = (word_t*) fifo->currentValue;
        printf("%s\t%d\n", s->word, s->line);
        fifo = fifo->next;
    }
}