//
//  kw_t.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include <stdlib.h>
#include <stdio.h>
#define MAX_LINE 1000       //zakładamy, że słowo nie występuje więcej niż w 1000 linijek;

typedef struct KeyWord_t {
    char* keyword;          //słowo które podał urzytkownik; te którego szukał;
    int* lines;             //numery linii które te słowo zawierają;
    int numberOfApperance;  //ile razy te słowo występuje;
}kw_t;

kw_t* initKeyWord(char* keyword){           //funkcja do inicjowania nowego słowa; Tworzy nowe słowo gdzie lines = NULL i numberOfApperance = 0;
    
    if(keyword == NULL){                    //sprawdzamy czy nowy keyword nie jest pusty
        fprintf(stderr,"ERROR: New keyword is empty string!");
        return NULL;
    }
    
    
    kw_t* kw = (kw_t*)malloc(sizeof(kw_t)); //pamiętać o free_kw() przy inicjowaniu !!!;
    if(kw == NULL){                         //malloc się może nie udać;
        fprintf(stderr,"ERROR: While allocating memory to new keyword: \"%s\"\n",keyword);
        return NULL;
    }
    
    
    kw->keyword = keyword;
    kw->numberOfApperance=0;
    
    
    kw->lines=(int*)malloc(MAX_LINE * sizeof(int));     //pamiętać o free_kw() przy inicjowaniu !!!;
    if(kw->lines == NULL){                              //malloc się może nie udać;
        fprintf(stderr,"ERROR: While allocating memory to new keyword->lines: \"%s\"\n",keyword);
        return NULL;
    }
    
    
    return kw; // zwracamy wskaźnik na nowy KeyWord jeśli wszystko git;
}

void free_kw(kw_t* kw){
    if(kw == NULL){                    //sprawdzamy czy keyword nie jest pusty;
        fprintf(stderr,"ERROR: Cannot free empty kw_t!");
        return NULL;
    }
}
