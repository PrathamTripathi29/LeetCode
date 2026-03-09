class Solution {
public:
    int mod = 1e9+7;
    int f(int z, int o, int c, int zero, int one, int limit, vector<vector<vector<int>>>& dp){
        if(z == zero && o == one) return 1;
        if(dp[z][o][c] != -1) return dp[z][o][c];
        else {
            long long ans = 0;
            if(c != 0){
                for(int d=1; d<=limit && z + d <= zero; d++){
                    ans = (ans + f(z + d, o, 0, zero, one, limit, dp))%mod;
                }
            }
            if(c != 1){
                for(int d=1; d<=limit && o + d <= one; d++){
                    ans = (ans + f(z, o + d, 1, zero, one, limit, dp))%mod;
                }
            }
            return dp[z][o][c] = ans;
        }
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1, vector<vector<int>>(one+1, vector<int>(3, -1)));
        return f(0, 0, 2, zero, one, limit, dp);
    }
};
