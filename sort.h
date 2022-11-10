#define SWAP(X, Y) {unsigned int TEMP = X; X = Y; Y = TEMP;}
#define MAX_SIZE 25

struct Sort {

    void (*bubleSort)(struct Sort * sort);
    void (*selectSort)(struct Sort * sort, unsigned int arr[]);
    void (*insertSort)(struct Sort * sort, unsigned int arr[]);

    unsigned int arr[MAX_SIZE];
    unsigned int length;

};

void buble_Sort(struct Sort * sort);
void select_Sort(struct Sort * sort, unsigned int arr[]);
void insert_Sort(struct Sort * sort, unsigned int arr[]);

struct Sort * sort_init(void) {
    
    struct Sort * sort = (struct Sort *)malloc(sizeof(struct Sort));
    
    sort->bubleSort = buble_Sort;
    sort->selectSort = select_Sort;
    sort->insertSort = insert_Sort;
    
    sort->length = MAX_SIZE;
        
    return sort;
}

void buble_Sort(struct Sort * sort) {

    for(int i = 0; i < sort->length; ++i) 
        for(int j = 0; j < sort->length -i-1; ++j) 
            if(sort->arr[j] > sort->arr[j+1]) 
                SWAP(sort->arr[j], sort->arr[j+1]);
            
                

    printf("정렬 후 : ");
    for(int i = 0; i < MAX_SIZE; ++i) 
        printf("%d ", sort->arr[i]);            
    return;
}

void select_Sort(struct Sort * sort, unsigned int arr[]) {

    int min;
    for(int i = 0; i < sort->length-1; ++i) {
        min = i;
        for(int j = i+1; j < sort->length; ++j) 
            if(arr[j] < arr[min])
                min = j;

        SWAP(arr[min], arr[i]);
    }
}

void insert_Sort(struct Sort * sort, unsigned int arr[]) {
    int key;
    for (int i = 1; i < sort->length; ++i) {
        key = arr[i];
        int j = i - 1;
        while (j >= 0 && sort->arr[j] > key) {
            sort->arr[j+1] = sort->arr[j];
            --j;
        }
        sort->arr[j+1] = key;
    }
}
