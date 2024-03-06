#include<vector>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> un_map;
    for (int i = 0; i < nums.size(); i++)
    {
        auto iter = un_map.find(target - nums[i]);
        if(iter != un_map.end()){
            return {iter->second,i};
        }
        un_map.insert(pair<int,int> (nums[i],i));
    }
    return {};
    

}