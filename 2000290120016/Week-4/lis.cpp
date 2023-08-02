/*
    Code of Longest Increasing Subsequence
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>

using std::cout;
using std::endl;
using std::max;

int lis(int a[], int n) {
    int dp[n] = { 1, 0 };

    for(int i=1 ; i<n ; ++i) {
        dp[i] = 1;

        for(int j=0 ; j<i ; ++j) if(a[i] > a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
    }
    
    int mx = dp[0];
    for(int i=1 ; i<n ; ++i) mx = max(dp[i], mx);
    return mx;
}

int main() {
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of lis is " <<  lis(arr, n) << endl;
    return 0;
}