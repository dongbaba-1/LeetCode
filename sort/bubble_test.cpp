#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void BubbleSort(int* arr,int n){
    int end = n;
    while (end > 0)
    {
        for (int j = 0; j < end - 1;j++)
        {
            if(arr[j] > arr[j+1])
                swap(&arr[j],&arr[j+1]);
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