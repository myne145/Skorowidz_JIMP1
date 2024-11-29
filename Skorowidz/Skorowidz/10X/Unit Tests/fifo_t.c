//
//  fifo_t.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 26/11/2024.
//


#include "../Headers/fifo_t.h"
#include "../Headers/kw_t.h"
#include <stdio.h>

int main(void){
    
    kw_t* kw1 = keyWordInit("Keyword");
    kw_t* kw2 = keyWordInit("KW2");
    
    fifo_t* que1 = init(kw1);
    push(que1, kw2);
    
    print_fifo(que1);
    
    kw_t* kw3 = pop(&que1);
    
    print_fifo(que1);
    
    push(que1, kw3);
    
    print_fifo(que1);
}
