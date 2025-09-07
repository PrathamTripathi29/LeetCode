class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -1e9;
        for(int i=0; i<n; i++){
                dp[i+1][0] = max(prices[i] + dp[i][1], dp[i][0]);
                dp[i+1][1] = max(-prices[i] + dp[i][0], dp[i][1]);
        }
        return dp[n][0];
    }
};
