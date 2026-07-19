class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long ans = s + (long long)n/2*m - (n/2 - 1);
        return ans;
    }
};
