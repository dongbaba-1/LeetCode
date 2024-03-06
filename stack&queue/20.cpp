#include<stack>
#include<iostream>
using namespace std;

bool isBracketValid(string s) {
    //遍历字符串
    char target;//定义一个当前需要的目标
    stack<char> bracketStack;//存放括号的栈
    for(int i = 0;i < s.size();++i){
        while(s[i] == '[' || s[i] == '{' || s[i] == '('){
            bracketStack.push(s[i]);
            if(s[i] == '[')
                target = ']';
            else if(s[i] == '{')
                target = '}';
            else
                target = ')';
            i++;
        }
        if(bracketStack.empty()){//当栈空时遇到了，遇到了右括号，则也是匹配错误
            return false;
        }
        if(s[i] == target){
            bracketStack.pop();//匹配上最顶上的括号，则弹出栈
            if(bracketStack.empty())
                continue;

            if(bracketStack.top() == '[')
                target = ']';
            else if(bracketStack.top() == '{')
                target = '}';
            else
                target = ')';
        }
        else{//匹配错误
            return false;
        }
    }
    if(!bracketStack.empty()){//最后如果多了一个左括号，则会剩在栈里
        return false;
    }
    return true;
        
}

int main(int argc, char const *argv[])
{
    string s = "()]";
    if(isBracketValid(s)){
        cout<<"匹配"<<endl;
    }
    else
        cout<<"不匹配"<<endl;
    return 0;
}

