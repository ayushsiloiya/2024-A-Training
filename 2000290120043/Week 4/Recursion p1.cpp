// program to calculate power of x (leetcode)

class Solution {
public:

    double power(double x, long long n){
        if(n==0) return 1;
        if(n&1) return x*power(x,n-1);
        else return power(x*x,n/2);
    }
    double myPow(double x, int n) {
        long long nn = n;
        if(nn<0) nn = -1*nn;
        double ans = power(x,nn);
        if(n<0) return (double)1.0/(double)ans;
        return ans;
    }
};