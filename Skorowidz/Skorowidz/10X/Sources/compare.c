//
//  compare.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "../Headers/compare.h"

#include <stdio.h>
#include <string.h>

int word_asci_value(char* word) {
    int val1 = 0;
    for(int i = 0; i < strlen(word); i++) {
        val1+= word[i];
    }
    return val1;
}

int compare(const void* kw1,const void* kw2){
    
    kw_t* w1 = *(kw_t**)kw1;
    kw_t* w2 = *(kw_t**)kw2;
    return (w2->numberOfApperance)-(w1->numberOfApperance);
}

int compare_alphabet(const void* kw1, const void* kw2) {
    kw_t* w1 = *(kw_t**)kw1;
    kw_t* w2 = *(kw_t**)kw2;

    return word_asci_value(w1->keyword) - word_asci_value(w2->keyword);
}
