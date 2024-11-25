#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"


int main() {
    fifo_t* fifo = init("test");

    push(fifo, "1");
    push(fifo, "2");
    push(fifo, "3");
    push(fifo, "4");
    push(fifo, "5");


//    while(fifo->next != NULL) {
//        void* str = fifo->currentValue;
//        printf("%s ", str);
//        fifo = fifo->next;
//    }
//    printf("\n");
    char* str = fifo->currentValue;
    printf("Wartość początkowa:\t%s\n", str);
    printf("Długość:\t%d\n\n", length(fifo));

    char* removedValue = pop(&fifo);
    printf("Zdjeta wartosc:\t%s\n", removedValue);

    str = (char*) fifo->currentValue;
    printf("Wartosc początkowa po zdjęciu:\t%s\n", str);
    printf("Długość po zdjęciu:\t%d", length(fifo));

}
