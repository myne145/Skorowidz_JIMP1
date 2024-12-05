//
// Created by antekk on 11/28/24.
//
#include "../Headers/kw_t.h"
#include "../Headers/fifo_t.h"
#include "../Headers/load_file.h"

#include <stdlib.h>
#include <string.h>
kw_t** find_keyword(fifo_t* fifo, char** word, int n) {
    if (!fifo || !word || n <= 0) {
        return NULL; // Zwróć NULL, jeśli wejściowe dane są nieprawidłowe
    }

    // Alokacja pamięci dla tablicy wskaźników
    kw_t** keywords = malloc(n * sizeof(kw_t*));
    if (!keywords) {
        return NULL; // Obsługa błędu alokacji pamięci
    }

    // Inicjalizacja struktury kw_t dla każdego słowa
    for (int i = 0; i < n; i++) {
        if (word[i] != NULL) {
            keywords[i] = keyWordInit(word[i]);
        } else {
            keywords[i] = NULL; // Ustawienie na NULL w przypadku pustego słowa
        }
    }

    // Przechodzenie przez kolejkę FIFO
    while (length(fifo)!=0) { // Zakładam, że is_empty sprawdza, czy FIFO jest puste
        word_t* wordAndNumber = pop(&fifo); // Pobranie elementu z kolejki
        if (!wordAndNumber) {
            continue; // Pomijamy puste elementy
        }

        // Przeszukiwanie tablicy słów
        for (int i = 0; i < n; i++) {
            if (keywords[i] != NULL && word[i] != NULL) {
                if (strcmp(word[i], wordAndNumber->word) == 0) {
                    addNewLineToKw(keywords[i], wordAndNumber->line);
                }
            }
        }

        // Zwolnienie pamięci pobranego elementu (jeśli jest dynamicznie alokowany)
        free(wordAndNumber);
    }

    return keywords;
}
