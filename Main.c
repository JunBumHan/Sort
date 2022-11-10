#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include <time.h>
#include "sort.h"

int main() {
    
    struct Sort * sort = sort_init();
    
    printf("정렬 전: ");
    srand((unsigned)time(NULL));
    for(int i = 0; i < 25; ++i) {
        printf("%d ", sort->arr[i] = rand()%101);
    }

    printf("sort->arr(%%p) : %p", sort->arr);

    puts("\n");
    sort->bubleSort(sort);

    // for(int i = 0; i < 25; ++i) {
    //     printf("%d ", sort->arr[i]);
    // }
}