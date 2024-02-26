#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fastIndex = 0;
        int slowIndex = 0;
        while (fastIndex < nums.size())
        {
            if(nums[fastIndex] != val){
                nums[slowIndex] = nums[fastIndex];
                fastIndex++;
                slowIndex++;
                
            }
            else{
                //while(nums[fastIndex]==val&&fastIndex < nums.size())
                    fastIndex++;//找最近一个不等于val的元素位置
            }

        }
        return slowIndex;
    }
    

};
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vector = {3,2,2,3};
    cout << s.removeElement(vector,2)<<endl;
    
    return 0;
}

