#include <iostream>
using namespace std;

void insertSort(int* array,int n){
    for (int i = 0; i < n-1; i++)
    {
        int end = i;
        int x = array[end + 1];//第一个元素默认排号，从第二个元素开始
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

//从大到小
void insertSort2(int* array,int n){
    for (int i = 0; i < n-1; i++)
    {
        int end = i;
        int x = array[end + 1];//第一个元素默认排号，从第二个元素开始
        while (end >= 0)
        {
            if(x > array[end]){
                array[end + 1] = array[end];//元素后移
                end--;
            }
            else
                break;
        }
        array[end + 1] = x;
        
    }
    
}

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


void BubbleSort(int* arr,int n){
    int end = n;
    while (end > 0)
    {
        for (int j = 0; j < end - 1;j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr,j,j+1);
        }
        end--;
    }
    
}
int main(int argc, char const *argv[])
{
    int array[] = {5,10,7,32,76,49,8,12};
    //insertSort2(array,8);
    //SelectSortOpt(array,8);
    BubbleSort(array,8);
    for (int i = 0; i < 8; i++)
    {
        cout<<array[i] <<" ";
    }
    
    return 0;
}
