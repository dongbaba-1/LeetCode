#include <vector>
#include <iostream>
using namespace std;

int max(int a,int b){
    return a<b?b:a;
}

int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = dp[0];
    for(int i = 1;i<nums.size();++i){
        dp[i] = max(dp[i-1] + nums[i],nums[i]);
        if(dp[i] > result){
            result = dp[i];
        }
    }
    return result;

}