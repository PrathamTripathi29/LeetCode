class Solution {
public:
    static const long long mod = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= mod;

        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }
    int sumOfNumbers(int l, int r, int k) {
        long long x = 0;
        for(int i = l; i<=r; i++){
            x += i;
        }
        int d = r - l + 1;
        long long y = modPow(d, k-1);
        
        x = (x * y)%mod;
        long long gp = (modPow(10, k) - 1 + mod)%mod;
        gp = gp*modPow(9, mod-2)%mod;
        long long ans = (x*gp)%mod;
        return (int)ans;
    }
};
