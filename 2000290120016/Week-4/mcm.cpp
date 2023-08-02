/*
    Code of Matrix Chain Multiplication
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>
#include <cstring>

using std::cout;
using std::min;

int dp[100][100];

int MCM(int p[], int i, int j) {
    if(i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    dp[i][j] = INT_MAX;
    for(int k=i ; k<j ; ++k) dp[i][j] = min(dp[i][j], MCM(p, i, k) + MCM(p, k+1, j) + p[i-1]*p[k]*p[j]);

    return dp[i][j];
}

int main() {
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));
 
    cout << "Minimum number of multiplications is " << MCM(arr, 1, size-1);
    return 0;
}