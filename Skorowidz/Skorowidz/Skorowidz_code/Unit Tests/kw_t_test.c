//
//  kw_t_test.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "kw_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

int main(void){
    char* str1 = "String1";
    kw_t* kw1 = keyWordInit(str1);
    
    int test1 = strcmp(kw1->keyword,"String1")==0   ? 1 : 0;  //sprawdza czy keyword został poprawnie zapisany;
    int test2 = kw1->lines != NULL                  ? 1 : 0;  //sprawdza czy pamięć została poprawnie przypisana do tablicy linii występowania;
    int test3 = kw1->numberOfApperance == 0         ? 1 : 0;  //sprawdza czy ilośc występowania jest równa 0;
    
    print_test(test1, "test1");
    print_test(test2, "test2");
    print_test(test3, "test3");
    
    
    
    addNewLineToKw(kw1,1);
    addNewLineToKw(kw1,2);
    addNewLineToKw(kw1,1);

    int test4 = kw1->numberOfApperance == 3 && kw1->linesSize == 2 && kw1->lines[0] == 1 && kw1->lines[1] == 2 && kw1->lines[2] == 0 ? 1 : 0;
    
    print_test(test4, "test4");
    
    
    
    freeKw(&kw1);
    
    int test5 = kw1 == NULL                         ? 1 : 0; //sprawdza pamięć jest odpowiednio zwolniona;
    
    print_test(test5, "test5");
    
    
    
    return 0;
}
