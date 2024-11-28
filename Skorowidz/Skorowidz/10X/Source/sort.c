//
//  sort.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 26/11/2024.
//

#include "../Headers/compare.h"
#include "../Headers/fifo_t.h"
#include "../Headers/kw_t.h"
#include <stdio.h>
#include <stdlib.h>

void freeFifoWithoutData(fifo_t** fifo){
    while(fifo){
        fifo_t* temp = *fifo;
        if(*fifo==NULL) break;
        *fifo = temp->next;
        free(temp);
    }
}

kw_t** fifoToList(fifo_t* que){
    kw_t** newList = malloc(length(que) * sizeof(kw_t*));
    //fifo_t* ogque = que;
    kw_t** out = newList;
    while(que!=NULL){
        if(que->currentValue!=NULL){
            kw_t* temp = (kw_t*)que->currentValue;
            *newList = temp;
            newList++;
        }
        que = que->next;
    }
    //que = ogque;
    freeFifoWithoutData(&que);
    return out;
}


fifo_t* listToFifo(kw_t** list,int size){
    if(list[0] != NULL){
        fifo_t* que = init(list[0]);
        for(int i = 1; i < size; i++){
            push(que, list[i]);
        }
        return que;
    }
    return NULL;
}

fifo_t* sortFifo(fifo_t* que){
    
    kw_t** list = fifoToList(que); //mempruf
        
    qsort(list, length(que), sizeof(kw_t*), compare);
    
    fifo_t* sque = listToFifo(list, length(que));
    
    free(que);
    free(list);
    
    return sque;
}


int main(void){
    kw_t* kw1 = keyWordInit("Keyword1");
    kw_t* kw2 = keyWordInit("Keyword2");
    kw_t* kw3 = keyWordInit("Keyword3");
    kw_t* kw4 = keyWordInit("Keyword4");
    
    kw1->numberOfApperance = 1;
    kw2->numberOfApperance = 2;
    kw3->numberOfApperance = 3;
    kw4->numberOfApperance = 4;
 
    fifo_t* que = init(kw1);
    push(que, kw2);
    push(que, kw3);
    push(que, kw4);
    
    fifo_t* sque = sortFifo(que);
    
    print_fifo(sque);
    
    while (1){
        
    }
}
