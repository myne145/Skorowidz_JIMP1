#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"
#include "Skorowidz/Skorowidz/10X/Headers/load_file.h"
#include "Skorowidz/Skorowidz/10X/Headers/search.h"

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Not enough arguments!\n"
                "Program arguments:\n"
               "\t- [program] <filename> <wordToFind1> <wordToFind2> <wordToFind...>\n"
               "\t- e.g. [program] example.txt hello world searches for words \"hello\" and \"world\"");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Failed to open the file!");
        return -2;
    }


    fifo_t *fifo = get_words(file);
    kw_t **keywords = find_keyword(fifo->next, argv + 2, argc - 2);

    for (int i = 0; i < argc - 2; i++) {
        printKw(*(keywords + i));
        freeKw((keywords + i));
    }

    //fifo zostało już wyczyszczone przez funkcję find_keyword, stąd brak free_fifo
    return 0;
}
