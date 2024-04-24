//我会的是挖坑法，以最左边的为基准数,则从end开始遍历
void FastSort(int* a,int begin,int end){
    int empty_flag;//判定是begin为空还是end为空,0表示begin位置是坑，1表示end位置是坑
    int key = a[0];
    // int begin = 0;
    // int end = n - 1;
    int left = begin;
	int right = end;
    empty_flag = 0;
    while (begin < end)
    {   
        if (empty_flag == 0){//若begin是坑，则调查end
            if(a[end] > key)
                end--;
            else{//把该数字填到begin的位置上
                a[begin] = a[end];
                begin++;
                empty_flag = 1;//现在end位置是坑了
            }
        }
        else{//若end是坑，则调查begin
            if(a[begin] < key)
                begin++;
            else{
                a[end] = a[begin];
                end--;
                empty_flag = 0;
            }
        }
    }
    //此时begin与end是重合的
    FastSort(a,left,end - 1);
    FastSort(a,begin + 1,right);
    
}