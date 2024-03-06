#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class MyQueue
{
public:
    deque<int> que;//使用deque实现单调队列
    //如果要移除的元素等于队列的出口元素，则弹出队列，否则不进行任何操作
    //这是因为push元素时保证了单调性，如果要移除的元素不是最大值（出口元素），在移除时压根就没在队列里
    void pop(int value){
        if(!que.empty() && value == que.front()){
            que.pop_front();//出口元素弹出
        }
        //其余无操作
    }

    //如果push元素比队列入口的元素大，则入口元素弹出，直到push元素小于等于入口元素
    //实现对必要元素的维护，没必要维护的元素直接弹出队列
    void push(int value){
        while(!que.empty()&&value > que.back()){
            que.pop_back();
        }
        que.push_back(value);
    }

    int front(){//返回最大元素
        return que.front();
    }

};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MyQueue myQueue;
    vector<int> result;
    //先把前k个元素推进队列
    for (int i = 0; i < k; i++)
    {  
       myQueue.push(nums[i]); 
    }
    result.push_back(myQueue.front());
    //然后开始返回最大值并推进滑动窗口
    //i指向待移除元素，j指向待入队列元素
    for(int i = 0,j = i + k;j <= nums.size();i++,j++){
        
        myQueue.pop(nums[i]);
        myQueue.push(nums[j]);
        result.push_back(myQueue.front());
    }
    return result;

}


int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int> result = maxSlidingWindow(nums,3);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i];
        /* code */
    }
    
    return 0;
}
