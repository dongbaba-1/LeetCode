#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >>k;
    cin.ignore();
    vector<int> vec;
    int temp;
    //先存进数组
    for(int i = 0;i<n;i++){
        cin >> temp;
        vec.push_back(temp);
    }
    //取绝对值后排序
    for (int i = 0; i < n; i++)
    {
        vec[i] = abs(vec[i]);
    }
    sort(vec.begin(),vec.end());
    int result = 0;
    
    int i = 0;
    while(vec[i] == 0)
        i++;
    result = i;
    //找到不为0的开始计算
    for(int j = i;j < vec.size();j++){
        if(k > vec[j]){
            k = k-vec[j];
            result++;
        }
        else//k<vec[j]，此时已经无法操作到0了
            break;
    }
    
    cout<<result<<endl;
    

    


}