//
//  test.c
//  Skorowidz
//
//  Created by Oskar Przybylski on 22/11/2024.
//
#include "test.h"
#include <stdio.h>

void print_test(int result,char* testName){
    if(result) printf("%s: Passed\n",testName);
    else       printf("%s: ERROR \n",testName);
}
