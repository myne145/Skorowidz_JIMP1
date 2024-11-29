//
//  compare.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "../Headers/compare.h"

int compare(const void* kw1,const void* kw2){
    
    kw_t* w1 = *(kw_t**)kw1;
    kw_t* w2 = *(kw_t**)kw2;
    return (w2->numberOfApperance)-(w1->numberOfApperance);
}
