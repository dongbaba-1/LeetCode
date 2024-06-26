#include <iostream>
using namespace std;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
//维护大根堆
//i为待维护节点下标
void heapify(int arr[],int n,int i){
    int largest = i;
    int lson = 2 * i + 1;
    int rson = 2 * i + 2;
    if(lson < n && arr[lson] > arr[largest])
        largest = lson;
    if(rson < n && arr[rson] > arr[largest])
        largest = rson;
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
    
}

//利用维护堆操作进行堆排序
void HeapSort(int* arr,int n){
    //首先把一个无序数组建成堆
    for(int i = n/2;i >= 0;i--){
        heapify(arr,n,i);
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {5,2,4,7,19,20,13};
    HeapSort(arr,7);
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}

