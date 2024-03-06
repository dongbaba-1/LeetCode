#include<iostream>
using namespace std;


void removeExtraSpace(string &s){
    //移除多余空格,但要注意的是每个单词之间必须保留一个空格
    int slowIndex = 0,fastIndex = 0;
    while(fastIndex < s.size()){
        if(s[fastIndex]!=' '){//不是空格，则依次覆盖
            s[slowIndex] = s[fastIndex];
            slowIndex++;
            fastIndex++;
        }
        else{//是空格，但如果slow不为0，说明不是初始的空格，则需要添上一个空格
            if(slowIndex != 0){
                s[slowIndex] = ' ';
                slowIndex++;
            }
            //单词之间只留一个空格，因此fastIndex要找下一个不是空格的位置
            while(s[fastIndex] == ' ')
                fastIndex++;
        }
    }
    //最后resize一下
    //因为在只要判断到s[fastIndex]为空格，且slowIndex != 0就会补一个空格，因此最后
    //多了一个空格，在resize时要去掉这个空格。
    //但还是有问题，如果最后没空格，则不会多添一个空格，
    //因此最正确的写法是先判断，
    if(s[s.size()-1] == ' '){//如果结尾有空格，则resize时去掉多添的空格
        s.resize(slowIndex-1);
    }
    else{//如果结尾没有空格，则直接resize
        s.resize(slowIndex);
    }
    
}
void reverseAll(string &s){
    //去掉空格后先整体翻转
    int lowIndex = 0;
    int highIndex = s.size() - 1;
    while(lowIndex < highIndex){
        char temp = s[lowIndex];
        s[lowIndex] = s[highIndex];
        s[highIndex] = temp;
        
        lowIndex++;
        highIndex--;
    }
}

void reverseWord(string &s){
    //然后翻转各个单词
    int index = 0;//标识每个单词之间的空格
    int lowIndex = 0;
    int highIndex = 0;
    while(index < s.size()-1)//要注意边界条件
    {   
        while(s[index] != ' ' && index < s.size()){
            index++;
        }
        highIndex = index - 1;
        while(lowIndex < highIndex){
            char temp = s[lowIndex];
            s[lowIndex] = s[highIndex];
            s[highIndex] = temp;
            
            lowIndex++;
            highIndex--;
        }
        lowIndex = index + 1;//low到下一个单词的起始位置
        index = lowIndex;//更新index的位置
    }
    
}

int main(int argc, char const *argv[])
{
    string s = "a good   example";
    cout<<s<<endl;
    removeExtraSpace(s);
    cout<<s<<endl;
    reverseAll(s);
    cout<<s<<endl;
    reverseWord(s);
    cout<<s<<endl;
    return 0;
}
