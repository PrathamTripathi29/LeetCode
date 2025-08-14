class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for(int i=0; i < n1; i++){
            for(int j=0; j < n2; j++){
                if(word1[i] == word2[j]) dp[i+1][j+1] = 1 + dp[i][j];
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }

        return (n1 - dp[n1][n2]) + (n2 - dp[n1][n2]);
    }
};
