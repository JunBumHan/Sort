#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include "sort.h"

int main() {
    
    struct Sort * sort = sort_init();

    srand((unsigned)time(NULL));
    for(int i = sort->startIdx; i < sort->length; ++i) 
        sort->arr[i] = rand()%101;


}

