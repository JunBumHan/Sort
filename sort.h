#define SWAP(X, Y) {int TEMP = X; X = Y; Y = TEMP;}
#define MAX_SIZE 10
#define SIZE 10

struct Sort {

    void (*bubleSort)(struct Sort * sort);
    void (*selectSort)(struct Sort * sort);
    void (*insertSort)(struct Sort * sort);
    void (*quickSort)(struct Sort * sort, int left, int right);
    void (*mergeSort)(struct Sort * sort, int left, int right);
    void (*heapSort)(struct Sort * sort);
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
void funcHeapSort(struct Sort * sort);
void funcPrint(struct Sort * sort);

struct Sort * sort_init(void) {
    
    struct Sort * sort = (struct Sort *)malloc(sizeof(struct Sort));
    
    // 메소드 (기능)
    sort->bubleSort = funcBubleSort;
    sort->selectSort = funcSelectSort;
    sort->insertSort = funcInsertSort;
    sort->quickSort = funcQuickSort;
    sort->mergeSort = funcMergeSort;
    sort->heapSort = funcHeapSort;
    sort->print = funcPrint;

    //변수 (속성)
    sort->length = SIZE;
    sort->startIdx = 0;
    sort->lastIdx = SIZE - 1;    
    
    return sort;
}

// BUBBLE SORT

// void funcBubleSort(...)  
// Buble sort의 시작점 이며, 정렬을 수행합니다. (반환값은 존재하지 않으며, 순차적입니다. ) 
void funcBubleSort(struct Sort * sort) {

    for(int i = 0; i < sort->length; ++i)           // i(0) ~ (arr의 길이 - 1)
        for(int j = 0; j < sort->length -i-1; ++j)  // j(0) ~ (arr의 길이 - i - 1)
            if(sort->arr[j] > sort->arr[j+1])       // 가정 : arr[j] > [j + 1]
                SWAP(sort->arr[j], sort->arr[j+1]); // SWAP!
    return;
}

// SELECT SORT

// void funcSelectSort(...)
// Select Sort의 시작점 이며, 정렬을 수행합니다. (반환값은 존재하지 않으며 순차적입니다.)
void funcSelectSort(struct Sort * sort) {

    int min;
    for(int i = 0; i < sort->length-1; ++i) {   // i(0) ~ (arr의 길이 - 2)
        min = i;                                // min = i (min은 값이 아닌 색인[index]을 저장합니다.)
        for(int j = i+1; j < sort->length; ++j) // j(i+1) ~ (arr의 길이 -1)
            if(sort->arr[j] < sort->arr[min])   // 가정 : arr[j] > arr[min]
                min = j;                        // min = j

        SWAP(sort->arr[min], sort->arr[i]);     // 제일 작은 값을 i색인(index) 값 이랑 교환
    }

    return;
}

// INSERT SORT

// void funcInsertSort(...)
// Insert Sort의 시작점 이며, 정렬을 수행합니다. (반환값은 존재하지 않으며 순차적입니다.)
void funcInsertSort(struct Sort * sort) {
    int key;
    for (int i = 1; i < sort->length; ++i) {    // i(1) ~ (arr의 크기 - 1)
        key = sort->arr[i];                     // key = arr[i]
        int j = i - 1;                          // j = i - 1;
        while(j >= 0 && sort->arr[j] > key) {   // j >= 0 && arr[j] > key
            sort->arr[j+1] = sort->arr[j];      // 앞에 덮어쓰기
            --j;                                // 뒤칸으로 가기
        }
        sort->arr[j+1] = key;                   // 값 대입
    }

    return;
}

// QUICK SORT

// void partition(...) 
// Quick sort에 분활부분을 담당하며, pivot 기준으로 왼쪽은 작은 값들, 오른쪽은 큰 값들로 정렬됩니다. (반환값 pivot의 색인(index)를 반환합니다, 순차적입니다.)
int partition(struct Sort * sort, int left, int right) {
    int pivot = sort->arr[right];   // 배열의 맨 오른쪽 값을 pivot으로 설정합니다.
    int i = (left - 1);             // i의 값은 left - 1 (작은 값을 추적함)

    for(int j = left; j <= right - 1; ++j) {    // j(left) ~ right - 1
        if(sort->arr[j] <= pivot) {             // 가정 : arr[j] <= pivot 
            ++i;                                
            SWAP(sort->arr[i], sort->arr[j]);   // arr[i] 랑 arr[j] 교환
        }
    }
    SWAP(sort->arr[i + 1], sort->arr[right]);   // pivot이랑 i + 1 을 교환 -> pivot 기준으로 왼쪽에는 pivot보다 작은 값들, 오른쪽에는 pivot보다 큰 값들
    return (i + 1);     // pivot의 위치 반환
}

// void funcQuickSort(...) 
// Quick sort의 시작점이며,정복을 시행하며, 분활 함수를 호출합니다.(반환값 pivot의 색인(index)를 반환합니다, 순차적입니다.)
void funcQuickSort(struct Sort * sort, int left, int right) {
    
    if(left< right) {   // 가정 : 원소 개수 판단 (원소의 개수가 하나 초과이면 TRUE, 원소의 개수가 하나면 FALSE)
        
        int pivot = partition(sort, left, right);   // 분활 : partition 함수는 pivot 의 색인(index)를 반환합니다.

        sort->quickSort(sort, left, pivot - 1);     // 정복 : left ~ pivot - 1 부분을 정복합니다.
        sort->quickSort(sort, pivot + 1, right);    // 정복 : pivot + 1 ~ right 부븐을 정복합니다.
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
        if(sort->arr[i] <= sort->arr[j])        // 가정 : mid 기준으로 앞의 배열의 i 번째 값 <= mid 기준으로 뒤의 배열의 j 번째 값 
            sort->temp[k++] = sort->arr[i++];   // temp 배열에 삽입
        else                                
            sort->temp[k++] = sort->arr[j++];   // temp 배열에 삽입
    }
    
    // 남아 있는 레코드 일괄 복사
    if(i > mid) // 가정 : mid 기준으로 앞의 배열을 다 복사 했다면
        for(int l = j; l <= right; ++l)         // j ~ right 
            sort->temp[k++] = sort->arr[l];     // 복사
    else // mid 기준으로 뒤의 배열을 다 복사 했다면
        for(int l = i; l <= mid; ++l)           // i ~ mid
            sort->temp[k++] = sort->arr[l];     // 복사
    
    // temp의 배열의 값을 arr에 재복사
    for(int l=left; l <= right; ++l)    // 시작 ~ 끝
        sort->arr[l] = sort->temp[l];   // 복사

    return;
}



// void funcMergeSort(...)  
// Merge sort의 시작점 이며, 분활과 정복을 시행하고 결합 함수를 호출합니다. (반환값은 존재하지 않으며, 재귀입니다. ) 
void funcMergeSort(struct Sort * sort, int left, int right) {

    if(left < right) {  // 가정 : 원소 개수 판단 (원소의 개수가 하나 초과이면 TRUE, 원소의 개수가 하나면 FALSE)

        int mid = (left+right) / 2;    // 분활 : mid = 배열의 중간 색인(index)값 

        sort->mergeSort(sort, left, mid);       // 정복 : mid 기준으로 앞의 배열    
        sort->mergeSort(sort, mid + 1, right);  // 정복 : mid 기준으로 뒤의 배열

        merge(sort, left, mid ,right);          // 결합 : 정렬된 2개의 부분 배열을 합병함
    }

    return;
}

// HEAP SORT

void insertMaxHeap(struct Sort * sort, int item, int heapIndex) {
    int i = heapIndex;
    while((i != 1) && (item > sort->arr[i/2])) {
        sort->arr[i] = sort->arr[i/2];
        i /= 2;
    }
    sort->arr[i] = item;
}

int deleteMaxheap(struct Sort * sort, int heapIndex) {
    int parent, child, item, temp;
    item = sort->arr[1];
    temp = sort->arr[heapIndex];
    parent = 1, child = 2;
    while(child <= heapIndex) {
        if((child < heapIndex) && (sort->arr[child] < sort->arr[child+1]))
            child++;
        if(temp >= sort->arr[child]) break;
        sort->arr[parent] = sort->arr[child];
        parent = child;
        child *= 2;
    }
    sort->arr[parent] = temp;
    return item;
}

void funcHeapSort(struct Sort * sort) {
    int heapIndex = 0;
    for(int i = 0; i < sort->length; ++i) {
        heapIndex++;
        insertMaxHeap(sort, sort->arr[i], heapIndex);
    }

    for(int i = sort->length-1; i >= 0; --i) {
        sort->arr[i] = deleteMaxheap(sort, heapIndex);
        heapIndex--;
    }
}
//// 쌤.

// Array print
void funcPrint(struct Sort * sort) {
    for(int i = 0; i < sort->length; ++i) 
        printf("%d ", sort->arr[i]);
    
    return;
}
