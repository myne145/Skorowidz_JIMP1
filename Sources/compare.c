//
//  compare.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "../Headers/compare.h"
#include <string.h>
#include <stdlib.h>

int compare(const void* kw1, const void* kw2) {
    // Rzutowanie wskaźników na wskaźniki do kw_t*
    const kw_t* w1 = *(const kw_t**)kw1;
    const kw_t* w2 = *(const kw_t**)kw2;

    // Obsługa przypadku NULL dla bezpieczeństwa
    if (!w1 || !w2) {
        return ((w1 == NULL) - (w2 == NULL)); // NULL traktowany jako "mniejszy"
    }

    // Porównanie liczby wystąpień (malejąco)
    return (w2->numberOfApperance) - (w1->numberOfApperance);
}

int compare_alphabet(const void* kw1, const void* kw2) {
    // Rzutowanie wskaźników na wskaźniki do kw_t*
    const kw_t* w1 = *(const kw_t**)kw1;
    const kw_t* w2 = *(const kw_t**)kw2;

    // Obsługa przypadków NULL
    if (!w1 || !w2) {
        return (w1 == NULL) - (w2 == NULL); // NULL traktowany jako "mniejszy"
    }

    // Porównanie słów leksykograficznie
    return strcmp(w1->keyword, w2->keyword);
}
