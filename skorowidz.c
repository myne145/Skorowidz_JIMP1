#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"

int main() {
    fifo_t* fifo = init("test");

    push(fifo, "sdasddsa");

    printf("%d", length(fifo));

}
