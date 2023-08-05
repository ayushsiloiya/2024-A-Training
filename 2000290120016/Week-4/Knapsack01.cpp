/*
    Code of 0/1 Knapsack Problem
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>

using std::cout;
using std::endl;
using std::max;

int knapsack01(int w, int weight[], int profit[], int n) {
    int dp[w + 1] = { 0 };

    for(int i=1 ; i<=n ; ++i) for(int W=w ; W>=0 ; --W) if(weight[i-1] <= W)
        dp[W] = max(dp[W], dp[W - weight[i-1]] + profit[i-1]);
    
    return dp[w];
}

int main() {
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };

    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);

    cout << "Profit Array :" << endl;
    for(int i : profit) cout << i << " ";
    cout << endl << "Weight Array :" << endl;
    for(int i : weight) cout << i << " ";
    cout << endl << "The maximum profit sack's weight is " << knapsack01(W, weight, profit, n);
    return 0;
}