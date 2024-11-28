#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"
#include "Skorowidz/Skorowidz/10X/Headers/load_file.h"
#include "Skorowidz/Skorowidz/10X/Headers/search.h"

int main(int argc, char** argv) {
//    Argumenty:
//    "nazwa_pliku" slowo1 slowo2 ...
//    nazwa pliku - skąd czytamy słowa
//    slowo1,2 - słowa których szukamy
//

    if(argc < 3) {
        fprintf(stderr, "Nie wystarczająca liczba argumentów!");
        //TODO: jakiś help
        return -1;
    }

    FILE* file = fopen(argv[1], "r");

    if(file == NULL) {
        fprintf(stderr, "Nie udało się otworzyć pliku!");
        return -2;
    }


//    fifo_t* fifo = get_words(file);
//    print_fifo(fifo->next);
//    fifo_t* temp;

    fifo_t* fifo = get_words(file);
    kw_t** keywords = find_keyword(fifo->next, argv + 2, argc - 2);

    for(int i = 0; i < argc - 2; i++)
        printKw(*(keywords + i));

//    keywords;

//    kw_t *test = malloc(sizeof(kw_t*));
//    for(int i = 2; i < argc; i++) {
//
//        print_fifo(temp);
//        test = find_keyword(temp->next, argv[i]);
//        printKw(test);
//    }

//    freeKw(&test);
    //TODO: free fifo
    return 0;
}
