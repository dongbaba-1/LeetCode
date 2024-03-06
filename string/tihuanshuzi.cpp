#include<iostream>
using namespace std;

string tranferNumber(string s){
    int OldSize = s.size();
    //统计数字个数
    int count = 0
    for (int i = 0; i < OldSize; i++)
    {
        if(s[i] >= '0' && s[i] <= '9'){
            count++;
        }
    }
    //扩充数组大小
    s.resize(OldSize + count * 5);
    int newSize = s.size();
    //从后向前将数字替换为“number”
    for(int i = OldSize - 1,int j = newSize - 1;i<j;i--,j--){
        if(s[i] > '9' || s[i] < '0'){
            //是字母，则将该字母挪到j所指位置，i所指向位置会被number占位
            s[j] = s[i];
        }
        else{//是数字，则开始往前填number
            s[j] = 'r';
            s[j-1] = 'e';
            s[j-2] = 'b';
            s[j-3] = 'm';
            s[j-4] = 'u';
            s[j-5] = 'n';
            j -= 5;
        }
    }
    return s;

}