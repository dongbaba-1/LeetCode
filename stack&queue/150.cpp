#include<stack>
#include<iostream>
#include<vector>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<string> stack;
    for (int i = 0; i < tokens.size(); i++)
    {
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            int temp1 = stoi(stack.top());
            stack.pop();
            int temp2 = stoi(stack.top());
            stack.pop();
            int result = 0;
            if(tokens[i] == "+"){
                result = temp2 + temp1;
            
            }else if(tokens[i] == "-"){
                result = temp2 - temp1;
                
            }else if(tokens[i] == "*"){
                result = temp2 * temp1;
                
            }else if(tokens[i] == "/"){
                result = temp2 / temp1;
                
            }
            stack.push(to_string(result));
        }
        else{
            stack.push(tokens[i]);
        }
    }

    return stoi(stack.top());
}

int main(int argc, char const *argv[])
{
    vector<string>vector = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int result = evalRPN(vector);
    cout<<result<<endl;
    return 0;
}
