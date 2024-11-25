//
// Created by antekk on 11/24/24.
//

#ifndef SKOROWIDZ_JIMP1_FIFO_T_H
#define SKOROWIDZ_JIMP1_FIFO_T_H

typedef struct fifo_t {
    void* currentValue;
    struct fifo_t* next;
} fifo_t;

/**
 * zamienia wskaźnik do fifo na fifo->next
 * @param fifo wskaźnik do wskaźnika do fifo
 * @return wartość zdjętą z fifo
 */
void* pop(fifo_t* *fifo);

/**
 *
 * @param fifo
 * @param element element który chcemy wrzucić do fifo
 */
void push(fifo_t* fifo, void* element);


/**
 *
 * @param fifo
 * @return długość fifo
 */
int length(fifo_t* fifo);

/**
 *
 * @param fifo do zaincjalizowania
 * @param value wartość
 */
fifo_t* init(void* value);

#endif //SKOROWIDZ_JIMP1_FIFO_T_H
