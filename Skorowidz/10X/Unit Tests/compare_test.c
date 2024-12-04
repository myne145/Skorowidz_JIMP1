//
//  compare_test.c
//  Skorowidz1
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include <stdio.h>
#include "../Headers/compare.h"
#include "../Headers/test.h"

int main(void){
    kw_t* kw1 = keyWordInit("k1");
    kw_t* kw2 = keyWordInit("k2");
    
    print_test(!compare(kw1, kw2), "test1");
    
    (kw1->numberOfApperance)++;
    
    print_test(compare(kw1, kw2), "test2");
    
    (kw1->numberOfApperance)--;
    (kw2->numberOfApperance)++;
    
    print_test(compare(kw2, kw1), "test3");
    
    
    return 0;
}
