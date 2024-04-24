#include <iostream>
#include <vector>
using namespace std;

int vec_score(vector<int> &vec,int begin,int end){//begin、end代表的是下标
    int score = vec[begin];
    for(int i = begin,j = begin + 1;j<=end;i++,j++){
        if(vec[i] == vec[j]){//相等，则得分直接为0
            return 0;
        }
        score += vec[j];
    }
    return score;
}

int main() {
    int n;
    cin>>n;
    vector<int> vec;
    int temp;
    int i = 0;
    while(i<n&&cin>>temp){
        vec.push_back(temp);
        i++;
    }
    
    long long score = 0;
    //数组长度n为多少，子数组就有几种，但长度1得分均是0.所以是从2到n
    //子数组长度为m,则长度为m的子数组共有n+1-m个
    for(int i = 2;i<=n;i++){//i代表子数组的长度
        for(int j = 0;j <= n - i;j++){
                score += vec_score(vec, j, j + i - 1);
        }
    }
    cout<<score % 10000007<<endl;

}
// 64 位输出请用 printf("%lld")