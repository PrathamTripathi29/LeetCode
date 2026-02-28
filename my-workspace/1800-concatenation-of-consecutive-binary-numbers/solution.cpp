class Solution {
public:
    int concatenatedBinary(int n) {
        int mod = 1e9 + 7;
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            int rshift = 32 - __builtin_clz(i);
            ans = ans<<rshift;
            ans = (ans + i)%mod;
        }
        return ans;
    }
};
