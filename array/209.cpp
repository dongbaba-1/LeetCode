#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT32_MAX;
    int sum = 0;//滑动窗口之和
    int i = 0;//滑动窗口起始位置
    int sublength = 0;//滑动窗口长度
    for(int j = 0;j<nums.size();j++){
        sum += nums[j];
        while(sum >= target){
            sublength = j - i + 1;
            result = result < sublength?result:sublength;
            sum -=  sum[i];
            i++;
        }
    }

    return result == INT32_MAX?0:result;
}