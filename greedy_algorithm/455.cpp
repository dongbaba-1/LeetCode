#include "header.h"
int findContentChildren(vector<int>& g, vector<int>& s) {
    int num = 0;
    sort(s.begin(),s.end());
    for (int i = 0; i < s.size(); ++i)
    {
        for(int j = 0;j<g.size();++j){
            if(g[j] <= s[i]){
                g.erase(g.begin() + j);//学生被满足后就从数组中移除
                num++;
                break;
            }
        }

    }
    return num;
}

int main(int argc, char const *argv[])
{
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << findContentChildren(g,s)<<endl;
    return 0;
}
