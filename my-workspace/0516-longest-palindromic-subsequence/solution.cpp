class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        string revs = s;
        reverse(revs.begin(), revs.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i] == revs[j]){
                    dp[i+1][j+1] = 1 + dp[i][j];
                } else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[n][n];
    }
};
