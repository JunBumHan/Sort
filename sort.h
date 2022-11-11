#define SWAP(X, Y) {int TEMP = X; X = Y; Y = TEMP;}
#define MAX_SIZE 10
#define SIZE 10

struct Sort {

    void (*bubleSort)(struct Sort * sort);
    void (*selectSort)(struct Sort * sort);
    void (*insertSort)(struct Sort * sort);
    void (*quickSort)(struct Sort * sort, int left, int right);
    void (*mergeSort)(struct Sort * sort, int left, int right);
    void (*print)(struct Sort * sort);


    int arr[MAX_SIZE];
    int temp[MAX_SIZE];

    int length;
    int startIdx;
    int lastIdx;

};

void funcBubleSort(struct Sort * sort);
void funcSelectSort(struct Sort * sort);
void funcInsertSort(struct Sort * sort);
void funcQuickSort(struct Sort * sort, int left, int right);
void funcMergeSort(struct Sort * sort, int left, int right);
void funcPrint(struct Sort * sort);

struct Sort * sort_init(void) {
    
    struct Sort * sort = (struct Sort *)malloc(sizeof(struct Sort));
    
    // 메소드 (기능)
    sort->bubleSort = funcBubleSort;
    sort->selectSort = funcSelectSort;
    sort->insertSort = funcInsertSort;
    sort->quickSort = funcQuickSort;
    sort->mergeSort = funcMergeSort;
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

// Quick sort 
int partition(struct Sort * sort, int left, int right) {
    int pivot = sort->arr[right], i = (left - 1);

    for(int j = left; j <= right - 1; ++j) {
        if(sort->arr[j] <= pivot) {
            ++i;
            SWAP(sort->arr[i], sort->arr[j]);
        }
    }
    SWAP(sort->arr[i + 1], sort->arr[right]);
    return (i + 1);
}

void funcQuickSort(struct Sort * sort, int left, int right) {
    
    if(left< right) {
        
        int pivot = partition(sort, left, right);

        sort->quickSort(sort, left, pivot - 1);
        sort->quickSort(sort, pivot + 1, right);
    }

    return;
}

// MERGE SORT

// void merge(...) 
// Merge sort에 결합부분을 담당하며, 2개의 배열을 정렬하여 합병합니다. (반환값은 존재하지 않으며, 순차적입니다.)
void merge(struct Sort * sort, int left, int mid, int right) {  
    int i = left, j = mid+1, k = left;

    // 분활 정렬된 arr를 합병 
    while(i <= mid /*mid 기준으로 앞의 배열 판단*/ && j <= right /*mid 기준으로 뒤의 배열 판단*/) {
        if(sort->arr[i] <= sort->arr[j])        // mid 기준으로 앞의 배열의 i 번째 값 <= mid 기준으로 뒤의 배열의 j 번째 값 
            sort->temp[k++] = sort->arr[i++];   // temp 배열에 삽입
        else                                
            sort->temp[k++] = sort->arr[j++];   // temp 배열에 삽입
    }
    
    // 남아 있는 레코드 일괄 복사
    if(i > mid) // mid 기준으로 앞의 배열을 다 복사 했다면
        for(int l = j; l <= right; ++l)         // j ~ right 
            sort->temp[k++] = sort->arr[l];     // 복사
    else // mid 기준으로 뒤의 배열을 다 복사 했다면
        for(int l = i; l <= mid; ++l)        // i ~ mid
            sort->temp[k++] = sort->arr[l];     // 복사
    
    // temp의 배열의 값을 arr에 재복사
    for(int l=left; l <= right; ++l) 
        sort->arr[l] = sort->temp[l];

    return;
}



// void funcMergeSort(...)  
// Merge sort에 시작점 이며, 분활과 정복을 시행하고 결합 함수를 실행합니다. (반환값은 존재하지 않으며, 재귀입니다. ) 
void funcMergeSort(struct Sort * sort, int left, int right) {

    if(left < right) {  // 원소 개수 판단 (원소의 개수가 하나 초과이면 TRUE, 원소의 개수가 하나면 FALSE)

        int mid = (left+right) / 2;    // 분활 : mid = 배열의 중간 색인(index)값 

        sort->mergeSort(sort, left, mid);       // 정복 : mid 기준으로 앞의 배열    
        sort->mergeSort(sort, mid + 1, right);  // 정복 : mid 기준으로 뒤의 배열

        merge(sort, left, mid ,right);          // 결합 : 정렬된 2개의 부분 배열을 합병함
    }

    return;
}

// Array print
void funcPrint(struct Sort * sort) {
    for(int i = 0; i < sort->length; ++i) 
        printf("%d ", sort->arr[i]);
    
    return;
}
