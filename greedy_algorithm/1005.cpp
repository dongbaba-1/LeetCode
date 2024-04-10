#include "header.h"

int sum(vector<int> &nums){
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    
    return sum;
}

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());//默认升序
    int j = 0;//记录取反次数
    for(int i = 0;i < nums.size() && nums[i] < 0 && j < k;i++,j++){
        nums[i] = 0 - nums[i];
    }
    if(j == k)//次数刚好用完
        return sum(nums);
    else{//次数没用完，则表示所有的负数已经取反，此时判断剩余次数
        int rest_num = k - j;
        if(rest_num % 2 == 0){
            return sum(nums);
        }
        else{//剩余次数为奇数，给最小的正数取反
            sort(nums.begin(),nums.end());
            nums.front() = 0 - nums.front();
            return sum(nums);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> vec = {-4,-2,-3};
    largestSumAfterKNegations(vec,4);
    return 0;
}
