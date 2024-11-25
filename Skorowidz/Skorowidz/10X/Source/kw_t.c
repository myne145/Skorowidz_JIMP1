//
//  kw_t.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/kw_t.h"


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
    
    
    kw->lines=(int*)calloc(MAX_LINE,sizeof(int));       //pamiętać o free_kw() przy inicjowaniu !!!;
    if(kw->lines == NULL){                              //malloc się może nie udać;
        fprintf(stderr,"ERROR: While allocating memory to new keyword->lines: \"%s\"\n",keyword);
        free(kw->keyword);
        free(kw);
        return NULL;
    }
    kw->linesSize = 0;
    
    return kw; // zwracamy wskaźnik na nowy KeyWord jeśli wszystko git;
}

void freeKw(kw_t** kw){ //funkcja zwalniająca pamięć po strukturze keyWord; przyjmuje wskaźnik na wskaźnik na strunturę żeby móc operować na prawdziwych zmiennych w pamięci;
    if(kw == NULL || *kw == NULL){
        fprintf(stderr, "ERROR: Cannot free empty kw_t");
        return;
    }
    free((*kw)->keyword);
    (*kw)->keyword = NULL;
    
    free((*kw)->lines);
    (*kw)->lines = NULL;
    (*kw)->linesSize = 0;
    
    (*kw)->numberOfApperance = 0;
    
    free(*kw);
    (*kw) = NULL;
}

void addNewLineToKw(kw_t* kw,int newline){ //funckja dodająca do konretnego KeyWord linie w których wystepuje a także zwiększająca noa tego kw; funkcja sama sprawdza czy newline jest juz w liscie lines; jesli jest zwieksza tylko noa; jesli nie ma dodaje je do listy;
    int currentElement = kw->linesSize;
    if(kw->lines[currentElement]!=0){ //sprawdzanie czy nowy element napewno jest pusty
        fprintf(stderr, "ERROR: Lines[currentElement] not free!");
        return;
    }
    int isNewLineInKw = 0;
    for(int i = 0; i<kw->linesSize; i++){ //sprawdza czy element jest już w liście
        if(newline == kw->lines[i]){
            isNewLineInKw = 1;
            break;
        }
    }
    if(isNewLineInKw == 0){ //jeśli nie ma to dodaje
        kw->lines[currentElement] = newline;
        kw->linesSize++;
        kw->numberOfApperance++;
    }else{                  //jeśli jest to zwiększa tylko ilość występowania noa;
        kw->numberOfApperance++;
    }
}

void printKw(kw_t* kw){
    if(kw == NULL) return;
    printf("KeyWord: \"%s\" noa: %d lines: ",kw->keyword,kw->numberOfApperance);
    for(int i = 0; i<kw->linesSize; i++){
        printf("%d ",kw->lines[i]);
    }
    printf("\n");
}
