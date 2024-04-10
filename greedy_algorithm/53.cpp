#include "header.h"
int maxSubArray(vector<int>& nums) {
    int result = INT32_MIN;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        
        count += nums[i];
        if(count > result)
            result = count;
        if(count < 0){//放弃，从下一个元素重新累积
            count = 0;
        }
            
    }
    return result;
    
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
    return 0;
}
