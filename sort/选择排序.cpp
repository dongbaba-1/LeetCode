void swap(int* arr,int &a,int &b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    
}

void SelectSort(int* arr,int n){
    int i = 0;
    while (i<n)
    {
        //升序排列，小的往前排
        int min = i;
        for(int j = i;j < n;j++){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr,i,min);
        i++;
    }
}

//优化版本，一趟找到最大值和最小值
void SelectSortOpt(int* arr,int n){
    int begin = 0,end = n - 1;
    while (begin < n/2)
    {
        int min = begin;
        int max = end;
        for(int i = begin;i<=end;i++){
            if(arr[i] < arr[min])
                min = i;
            if(arr[i] > arr[max])
                max = i;
        }
        swap(arr,begin,min);
        swap(arr,end,max);
        begin++;
        end--;
    }
    
}