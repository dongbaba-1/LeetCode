#include "header.h"
bool canJump(vector<int>& nums) {
    if(nums.size() == 1)
        return true;
    int cover = 0;
    for (int i = 0; i <= cover; i++)
    {
        /*i 每次移动只能在 cover 的范围内移动，每移动一个元素，cover 得到该元素数值（新的覆盖范围）的补充，让 i 继续移动下去。

而 cover 每次只取 max(该元素数值补充后的范围, cover 本身范围)。
        */
        cover = max(i + nums[i], cover);
        if(cover >= nums.size() - 1)
            return true;
    }
    return false;
    
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {3,2,1,0,4};
    if(canJump(nums))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}