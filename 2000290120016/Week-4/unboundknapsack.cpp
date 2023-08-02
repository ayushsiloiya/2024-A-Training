/*
    Code of Unbounded Knapsack Problem
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>

using std::cout;
using std::endl;
using std::max;

int unbound_knapsack(int w, int wt[], int pr[], int n) {
    int dp[w] = { 0 };

    for(int i=0 ; i<=w ; ++i) for(int j=0 ; j<n ; ++j) if(wt[j] <= i)
        dp[i] = max(dp[i], dp[i - wt[j]] + pr[j]);
    
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
    cout << endl << "The unbounded maximum profit sack's weight is " << unbound_knapsack(W, weight, profit, n);
    return 0;
}