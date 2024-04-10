#include<iostream>
#include<vector>
using namespace std;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    //初始化，第一行和第一列的格子只要有一个障碍，这一行或一列之后的都是0
    for(int i = 1;i<=m;i++){
        //dp[i][1] = 1;
        if(obstacleGrid[i-1][0] == 1){
            for(int j = i;j<=m;j++){
                dp[j][1] = 0;
            }
            break;
        }
        else
            dp[i][1] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        //dp[1][i] = 1;
        if(obstacleGrid[0][i-1] == 1){
            for(int j = i;j<=n;j++){
                dp[1][j] = 0;
            }
            break;
        }
        else
            dp[1][i] = 1;
    }
    for(int i = 2;i<=m;i++){
        for (int j = 2; j <= n; j++)
        {
            if(obstacleGrid[i-1][j-1] == 1){
                dp[i][j] = 0;
            }
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m][n];
    
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
