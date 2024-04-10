#include<iostream>
#include<vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    //初始化，第一行和第一列的格子都只有一种方法
    for(int i = 1;i<=m;i++){
        dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = 1;
    }
    for(int i = 2;i<=m;i++){
        for (int j = 2; j <= n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
    
}

int main(int argc, char const *argv[])
{
    cout<<uniquePaths(3,3)<<endl;
    return 0;
}
