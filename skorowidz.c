#include <stdlib.h>
#include <stdio.h>
#include "Skorowidz/Skorowidz/10X/Headers/fifo_t.h"
#include "Skorowidz/Skorowidz/10X/Headers/load_file.h"

int main() {
    FILE* file = fopen("test_dane.txt", "r");
    get_words(file);

}
