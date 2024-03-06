#include<vector>
#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

class mycomparison
{
public:
    bool operator()(const pair<int,int>& lhs,const pair<int,int>& rhs){
        return lhs.second > rhs.second;
    }
};


vector<int> topKFrequent(vector<int>& nums, int k) {
    //使用map统计元素出现的次数
    unordered_map<int,int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    
    //对频率排序，定义一个小顶堆，大小为k
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycomparison> pri_que;

    for (auto iter = map.begin();  iter != map.end(); iter++)
    {
        pri_que.push(*iter);
        if(pri_que.size() > k){
            pri_que.pop();//堆的大小一大于k了，就把堆顶元素弹出，保持堆的大小为k
        }
    }

    //找出前k个高频元素，小顶堆，所以倒着往数组里存
    vector<int> result(k);
    for(int i = k-1;i>=0;i--){
        result[i] = pri_que.top().first;//取map的键
        pri_que.pop();
    }
    return result;
    
}
int main(int argc, char const *argv[])
{
    vector<int> sample = {1};
    vector<int> result = topKFrequent(sample,1);
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    
    return 0;
}
