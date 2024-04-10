void ShellSort(int* arr,int n){
    //排完一组再排下一组
    int gap = n;
    
    while (gap > 1)
    {
        gap = gap / 2;
        for (int i = 0; i < gap; i++){//gap也可以代表组数，有几组就排几次
            for (int j = i; j < n - gap;)//n-1变为n-gap
            {
                int end = j;
                int x = arr[end + gap];
                while (end >= 0 )
                {
                    if(x < arr[end]){
                        arr[end + gap] = arr[end];
                        end -= gap;
                    }
                    else{
                        break;
                    }
                }
                arr[end + 1] = x;
                j = j + gap;
            }
        }
    }
    
}