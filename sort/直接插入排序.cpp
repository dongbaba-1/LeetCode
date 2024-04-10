//array为待排序数组，n为数组元素个数
void insertSort(int* array,int n){
    for (int i = 0; i < n-1; i++)
    {
        int end = i;
        int x = array[end + 1];//i<n-1的原因，第一个元素默认排号，从第二个元素开始
        while (end >= 0)
        {
            if(x < array[end]){
                array[end + 1] = array[end];//元素后移
                end--;
            }
            else
                break;
        }
        array[end + 1] = x;
        
    }
    
}