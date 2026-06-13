class Solution {
public:
    double f(double x, long long n, double ans){
        if(n==0) return ans;
        if(n&1){
            ans *= x;
            n--;
        } else {
            x = x*x;
            n = n/2;
        }
        return f(x, n, ans);
    }
    double myPow(double x, int n) {
        long long m = n;
        double ans = f(x, abs(m), 1.0);
        if(m < 0) ans = 1/ans;
        return ans;
    }
};
