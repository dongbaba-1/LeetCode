#include "header.h"
int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() == 1)
        return 1;
    if(nums.size() == 2){
        if(nums[0] != nums[1])
            return 2;
        else
            return 1;
    }
    bool isAllSame = true;
    int a = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] == a){
            i++;
            continue;
        }
        else
            isAllSame = false;
    }
    if(isAllSame)
        return 1;
    int result1 = 0,result2 = 0;
    if(nums[0] != nums[1]){
        result1++;//第一个数肯定算
        result2++;
    }
    int flag;//0表示下一个找高位，1表示下一个要找低位
    
    //假设一开始为高位，则找低位
    flag = 1;
    int i = 0;
    int j = i+1;
    int k = j+1;
    while(k < nums.size()){
        if(flag == 1){
            if( nums[j] <= nums[i] && nums[j] < nums[k]){
                result1++;
                flag = 0;
            }
        }
        if(flag == 0){
            if(nums[j] >= nums[i] && nums[j] > nums[k]){
                result1++;
                flag = 1;
            }
        }
        i++;j++;k++;
    }
    //if(nums[i] != nums[j])
    result1++;

    //假设一开始为低位，则找高位
    flag = 0;
    i = 0;
    j = i+1;
    k = j+1;
    while(k < nums.size()){
        if(flag == 1){
            if( nums[j] <= nums[i] && nums[j] < nums[k]){
                result2++;
                flag = 0;
            }
        }
        if(flag == 0){
            if(nums[j] >= nums[i] && nums[j] > nums[k]){
                result2++;
                flag = 1;
            }
        }
        i++;j++;k++;
    }
    //if(nums[i] != nums[j])
    result2++;

    return result1 > result2 ? result1 : result2;

}