#include <stdio.h>
#include <stdlib.h>

#include "Headers/fifo_t.h"
#include "Headers/load_file.h"
#include "Headers/search.h"
#include "Headers/sort.h"
#include "Headers/kw_t.h"


int main(int argc, char** argv) {
    if (argc < 4) {
            fprintf(stderr, "Not enough arguments!\n"
                    "Program arguments:\n"
                   "\t- [program] <filename> <mode> <wordToFind1> <wordToFind2> <wordToFind...>\n"
                   "\t- e.g. [program] example.txt 1 hello world searches for words \"hello\" and \"world\""
                   "<mode> is the value we sort the results by - 0 is by appearance count, 1 is by ASCI");
            return -1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Failed to open the file! \n");
        return -2;
    }

    int mode = atoi(argv[2]);
        if(mode != 0 && mode != 1) {
            fprintf(stderr, "Invalid mode value - must be 0 or 1");
            return -3;
    }

    fifo_t *fifo = get_words(file);

    kw_t **keywords = find_keyword(fifo->next, argv + 3, argc - 2);
    int size = argc-2;
    
    
    fifo_t* kwlist = listToFifo(keywords,size);
    fifo_t* sortedlist = sortFifo(kwlist, mode);

    
    print_fifo_kw(sortedlist);

    //fifo zostało już wyczyszczone przez funkcję find_keyword, stąd brak free_fifo
    return 0;
}
