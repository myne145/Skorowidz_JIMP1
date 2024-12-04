//
//  kw_t.h
//  Skorowidz1
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#ifndef KW_T_H
#define KW_T_H
// Deklaracje struktury;
typedef struct keyWord_t {
    char* keyword;          //słowo które podał urzytkownik; te którego szukał;
    int* lines;             //numery linii które te słowo zawierają;
    int linesSize;          //ile pierwszych elementów tablicy lines jest zapełnionych;
    int numberOfApperance;  //ile razy te słowo występuje;
}kw_t;

// Deklaracje funkcji
kw_t* keyWordInit(const char* keyword);
void freeKw(kw_t** kw);
void addNewLineToKw(kw_t* kw,int newline);
void printKw(kw_t* kw);

// Makra
#define MAX_LINE 100        //zakładamy, że słowo nie występuje więcej niż w 100 linijek;
#define MAX_WORD 100        //zakładamy, że słowo nie ma więcej niż w 100 znaków;

#endif // KW_T_H

