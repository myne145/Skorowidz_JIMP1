//
//  compare.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "../Headers/compare.h"

int compare(const kw_t* kw1,const kw_t* kw2){
    return (kw1->numberOfApperance)-(kw2->numberOfApperance);
}
