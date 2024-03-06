#include<stack>
#include<iostream>
using namespace std;
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    MyQueue() {
        

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int pop = stOut.top();
        stOut.pop();
        return pop;
    }
    
    
    int peek() {
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }
    
    bool empty() {
        if(stIn.empty() && stOut.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main(int argc, char const *argv[])
{
   
    return 0;
}
