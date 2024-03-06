#include<vector>
#include<unordered_map>
using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int,int> un_map;
    int result = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            un_map[nums1[i] + nums2[j]]++;
            
        }
    }
    for(int i = 0;i<nums3.size();i++){
        for (int j = 0; j < nums4.size(); j++)
        {
            auto iter = un_map.find(0-(nums3[i] + nums4[j]));
            if(iter != un_map.end()){
                result += iter->second;
            }
        }
        
    }
    return result;
    
}