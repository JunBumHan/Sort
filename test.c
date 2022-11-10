#define SWAP(X, Y) {int TEMP = X; X = Y; Y = TEMP;}

#include <stdio.h>

int main(void) {
    int arr[10] = {3, 2, 1, 4, 5, 7, 6, 4, 1, 3};

    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10 - i - 1; ++j) {
            if(arr[j] > arr[j + 1])
                SWAP(arr[j], arr[j+1]);
        }
    }

    for(int i = 0; i < 10; ++i) 
        printf("%d ", arr[i])
}