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
 * usuwa pierwszy element z kolejki
 * @param fifo wskaźnik do wskaźnika na fifo
 * @return wartość zdjętą z fifo
 */
void* pop(fifo_t* *fifo);

/**
 * dodaje element do kolejki
 * @param fifo kolejka do której dodaje element
 * @param element element który chcemy wrzucić do fifo
 * @return 1 jeśli  udało się wrzucić wartość, 0 jeśli nie
 */
int push(fifo_t* fifo, void* element);


/**
 * liczy długość fifo
 * @param fifo kolejka dla której liczy długość
 * @return długość fifo
 */
int length(fifo_t* fifo);

/**
 * inicjalizuje kolejkę fifo
 * @param fifo do zaincjalizowania
 * @param value wartość początkowa
 */
fifo_t* init(void* value);

/**
 * wyszukuje DOKŁADNĄ wartość w kolejce
 * @param fifo do przeszukania
 * @param pattern do znalezienia
 * @return wskaźnik do elementu, jeśli nie ma takiego to NULL
 */
void* find(fifo_t* fifo, void* pattern);
void print_fifo(fifo_t* que);

void print_fifo(fifo_t* fifo);

#endif //SKOROWIDZ_JIMP1_FIFO_T_H
