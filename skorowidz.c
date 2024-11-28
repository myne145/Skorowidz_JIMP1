#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"
#include "Skorowidz/Skorowidz/10X/Headers/load_file.h"
#include "Skorowidz/Skorowidz/10X/Headers/search.h"

int main() {
    FILE* file = fopen("test_dane.txt", "r");
    fifo_t* fifo = get_words(file);
    print_fifo(fifo->next);
    kw_t* test = find_keyword(fifo->next, "niech");
    printKw(test);

    return 0;
}
