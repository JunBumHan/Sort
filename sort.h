#define SWAP(X, Y) {int TEMP = X; X = Y; Y = TEMP;}
#define MAX_SIZE 30
#define SIZE 10

struct Sort {

    void (*bubleSort)(struct Sort * sort);
    void (*selectSort)(struct Sort * sort);
    void (*insertSort)(struct Sort * sort);
    void (*quickSort)(struct Sort * sort, int start, int end);
    void (*print)(struct Sort * sort);


    int arr[MAX_SIZE];
    int length;

    int startIdx;
    int lastIdx;

};

void funcBubleSort(struct Sort * sort);
void funcSelectSort(struct Sort * sort);
void funcInsertSort(struct Sort * sort);
void funcQuickSort(struct Sort * sort, int start, int end);
void funcPrint(struct Sort * sort);

struct Sort * sort_init(void) {
    
    struct Sort * sort = (struct Sort *)malloc(sizeof(struct Sort));
    
    // 메소드 (기능)
    sort->bubleSort = funcBubleSort;
    sort->selectSort = funcSelectSort;
    sort->insertSort = funcInsertSort;
    sort->quickSort = funcQuickSort;
    sort->print = funcPrint;

    //변수 (속성)
    sort->length = SIZE;
    sort->startIdx = 0;
    sort->lastIdx = SIZE - 1;    
    
    return sort;
}

void funcBubleSort(struct Sort * sort) {

    for(int i = 0; i < sort->length; ++i) 
        for(int j = 0; j < sort->length -i-1; ++j) 
            if(sort->arr[j] > sort->arr[j+1]) 
                SWAP(sort->arr[j], sort->arr[j+1]);  
    return;
}

void funcSelectSort(struct Sort * sort) {

    int min;
    for(int i = 0; i < sort->length-1; ++i) {
        min = i;
        for(int j = i+1; j < sort->length; ++j) 
            if(sort->arr[j] < sort->arr[min])
                min = j;

        SWAP(sort->arr[min], sort->arr[i]);
    }

    return;
}

void funcInsertSort(struct Sort * sort) {
    int key;
    for (int i = 1; i < sort->length; ++i) {
        key = sort->arr[i];
        int j = i - 1;
        while (j >= 0 && sort->arr[j] > key) {
            sort->arr[j+1] = sort->arr[j];
            --j;
        }
        sort->arr[j+1] = key;
    }

    return;
}

int partition(struct Sort * sort, int l, int r) {
    int pivot = sort->arr[r], i = (l - 1);

    for(int j = l; j <= r - 1; ++j) {
        if(sort->arr[j] <= pivot) {
            ++i;
            SWAP(sort->arr[i], sort->arr[j]);
        }
    }
    SWAP(sort->arr[i + 1], sort->arr[r]);
    return (i + 1);
}

void funcQuickSort(struct Sort * sort, int l, int r) {
    
    if(l < r) {
        
        int pivot = partition(sort, l, r);

        sort->quickSort(sort, l, pivot - 1);
        sort->quickSort(sort, pivot + 1, r);
    }

    return;
}

void funcPrint(struct Sort * sort) {
    for(int i = 0; i < sort->length; ++i) 
        printf("%d ", sort->arr[i]);
    
    return;
}
