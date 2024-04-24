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
void HeapSort(int arr[],int n){
    //首先把一个无序数组建成堆
    for(int i = n/2-1;i >= 0;i--){
        heapify(arr,n,i);
    }
    //把根节点与最后一个节点交换，并调用堆维护操作重新调整为大根堆
    int end = n-1;
    int num = n;//当前剩余待排序节点数
    for (int i = 0; i < n; i++)
    {
        swap(arr[0],arr[end]);
        end--;
        num--;
        for(int j = num/2-1;j >= 0;j--){
            heapify(arr,num,j);
        }
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

