// Merge sort 최적화
void merge(int *list, int *help, int left, int mid, int right){

int i = left;
int j = mid+1;
int cur = left;

while( (i <= mid) && (j <= right)){
if(list[i] <= list[j])
help[cur++] = list[i++];
else
help[cur++] = list[j++];
}

while(i <= mid){
help[cur++] = list[i++];
}

for(int idx = left; idx < cur; idx++){
list[idx] = help[idx];
}
}