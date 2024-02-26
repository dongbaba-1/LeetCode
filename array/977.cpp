#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
    {   
        nums[i] = nums[i]*nums[i];//全部平方一遍
        
    }
    //然后排序，用冒泡排序嘛
    for(int i = 0;i<nums.size();i++){
        for(int j = 0;j<nums.size()-i-1;j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
    
}

vector<int> sortedSquares2(vector<int>& nums) {
    vector<int> result(nums.size());
    int index = result.size() - 1;
    int low = 0;
    int high = nums.size() - 1;
    while(low != high){
        if(abs(nums[low]) >= abs(nums[high])){
            result[index] = nums[low]*nums[low];
            low++;
        }
        else{
            result[index] = nums[high]*nums[high];
            high--;
        }
            
        index--;
    }
    result[0] = nums[low]*nums[low];//最后一个位置low与high重合时
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> vector1 = {-7,-3,2,3,11};

    vector<int> result = sortedSquares2(vector1);

    return 0;
}
