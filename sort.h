#define SWAP(X, Y) {int TEMP = X; X = Y; Y = TEMP;}

#include <time.h>
#include <string.h>

struct Sort {
    void(*bubleSort)(struct Sort * sort, unsigned int arr[]);
    unsigned int arr[25];
}

struct Sort * sort_init(void) {
    
    struct Sort * sort = (struct Sort)malloc(sizeof(struct Sort));

    sort->bubleSort = buble_Sort();

    for(int i = 0; i < 25; ++i) 
        sort->arr[i] = 0;

}

void buble_Sort(struct Sort * sort, unsigned int arr[]) {
    
    unsigned int arrLength = strlen(sort->arr);

    for(int i = 0; i < arrLength; ++i) {
        for(int j = 0; j < arrLength - i; ++j) {
            if(sort->arr[j] > sort->arr[j+1]) {
                SWAP(sort->arr[j], sort->arr[j+1]);
            }
        }
    }
}