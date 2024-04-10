#include<vector>
#include<iostream>
using namespace std;

//斐波那契数列
//用递归做
int fib(int n) {
    if(n ==0)
        return 0;
    else if(n == 1)
        return 1;

    return fib(n-2) + fib(n-1);
    
}

//用dp的思想
int fib2(int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    if(n == 0)
        return dp[0] = 0;
    dp[1] = 1;
    for(int i = 2;i<=n;++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{   
    cout<< fib(30)<<endl;
    
    return 0;
}
