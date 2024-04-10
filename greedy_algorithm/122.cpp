#include "header.h"
int maxProfit(vector<int>& prices) {
    vector<int> everyday_profit;
    for (int i = 0,j = 1; j < prices.size(); i++,j++)
    {
        everyday_profit.push_back(prices[j] - prices[i]);
    }
    int result =  0;
    for (int i = 0; i < everyday_profit.size(); i++)
    {
        if(everyday_profit[i] > 0)
            result += everyday_profit[i];
    }
    return result;
    
}