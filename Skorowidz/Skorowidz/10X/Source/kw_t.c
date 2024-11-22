//
//  kw_t.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "kw_t.h"


kw_t* keyWordInit(const char* keyword){     //funkcja do inicjowania nowego słowa; Tworzy nowe słowo gdzie lines = NULL i numberOfApperance = 0;
    
    if(keyword == NULL){                    //sprawdzamy czy nowy keyword nie jest pusty
        fprintf(stderr,"ERROR: New keyword is empty string!");
        return NULL;
    }
    
    
    kw_t* kw = (kw_t*)malloc(sizeof(kw_t)); //pamiętać o free_kw() przy inicjowaniu !!!;
    if(kw == NULL){                         //malloc się może nie udać;
        fprintf(stderr,"ERROR: While allocating memory to new keyword: \"%s\"\n",keyword);
        return NULL;
    }
    
    
    kw->keyword = strdup(keyword);                //unikamy sytuacji gdzie w main zostanie wywołane free(keyword) i stracimy ten string; Działa podobnie do malloca wiec tez pamietac o free_kw();
    if(strcmp(kw->keyword, keyword)!=0){
        fprintf(stderr,"ERROR: While coping keyword to new keyword->keyword: \"%s\"\n",keyword);
        free(kw->keyword);
        free(kw);
        return NULL;
    }
    
    kw->numberOfApperance=0;
    
    
    kw->lines=(int*)malloc(MAX_LINE * sizeof(int));     //pamiętać o free_kw() przy inicjowaniu !!!;
    if(kw->lines == NULL){                              //malloc się może nie udać;
        fprintf(stderr,"ERROR: While allocating memory to new keyword->lines: \"%s\"\n",keyword);
        free(kw->keyword);
        free(kw);
        return NULL;
    }
    
    return kw; // zwracamy wskaźnik na nowy KeyWord jeśli wszystko git;
}

void freeKw(kw_t** kw){ //funkcja zwalniająca pamięć po strukturze keyWord; przyjmuje wskaźnik na wskaźnik na strunturę żeby móc operować na prawdziwych zmiennych w pamięci;
    if(kw == NULL || *kw == NULL){
        fprintf(stderr, "ERROR: Cannot free empty kw_t");
    }
    free((*kw)->keyword);
    (*kw)->keyword = NULL;
    
    free((*kw)->lines);
    (*kw)->lines = NULL;
    
    (*kw)->numberOfApperance = 0;
    
    free(*kw);
    (*kw) = NULL;
}

