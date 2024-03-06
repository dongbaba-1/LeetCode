#include<stack>
#include<iostream>
using namespace std;
string removeDuplicates(string s) {
    stack<char> stackIn;
    for (int i = 0; i < s.size(); i++)
    {
        if(stackIn.empty())
            stackIn.push(s[i]);
        else if(s[i] == stackIn.top()){
            stackIn.pop();//相同则栈顶元素出栈
        }
        else{
            stackIn.push(s[i]);
        }
    }
    string result;
    result.resize(stackIn.size());
    for (int i = result.size() - 1; i >= 0; i--)
    {
        result[i] = stackIn.top();
        stackIn.pop();
    }
    return result;
    
}
int main(int argc, char const *argv[])
{
    string s = "azxxzy";
    cout<<removeDuplicates(s)<<endl;
    return 0;
}
