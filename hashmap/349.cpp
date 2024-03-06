#include<vector>
#include<unordered_set>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    //先把数据存进unordered_set完成去重操作
    unordered_set<int> num_set(nums1.begin(),nums1.end());
    unordered_set<int> result_set;
    for (int i = 0; i < nums2.size(); i++)
    {
        if(num_set.find(nums2[i]) != num_set.end())
        //find找到后返回指向位置的迭代器，未找到则返回指向end的迭代器
            result_set.insert(nums2[i]);//其实有可能重复插入
    }
    //转换为vector返回
    return vector<int> (result_set.begin(),result_set.end());
    

}