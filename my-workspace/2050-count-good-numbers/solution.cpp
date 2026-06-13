class Solution {
public:
    int mod = 1e9 + 7;
    long long f(long long b, long long e){
        long long ans = 1;
        while(e > 0){
            if(e&1){
                ans = (ans*b)%mod;
                e--;
            } else {
                b = (b*b)%mod;
                e = e/2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        int ans = 0;
        long long fours = n/2;
        long long fives = (n+1)/2;
        return (f(4, fours)*f(5, fives))%mod;
    }
};
