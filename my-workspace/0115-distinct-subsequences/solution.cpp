class Solution {
public:
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] == -1){
            if(s[i] == t[j]){
                return dp[i][j] = f(s, t, i-1, j, dp) + f(s, t, i-1, j-1, dp);
            } else{
                return dp[i][j] = f(s, t, i-1, j, dp);
            }
        }
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        int i = sl-1;
        int j = tl-1;
        vector<vector<int>> dp(sl+1, vector<int>(tl+1, 0));
        for(int i=0; i<=sl; i++){
            for(int j=0; j<=tl; j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }
                if(i == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (long long)dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[sl][tl];
    }
};
