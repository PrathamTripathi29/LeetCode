class Solution {
public:
    int f(int index, int stock, int bought, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
        if(index == n){
            return 0;
        }
        if(dp[index][stock][bought] != -1){
            return dp[index][stock][bought];
        } else{
        if(stock == 0){
            if(bought < 2)
                return dp[index][stock][bought] = max(f(index+1, 1, bought+1, prices, n, dp) + (-prices[index]), f(index+1, 0,bought, prices, n, dp));
            else
                return dp[index][stock][bought] = f(index+1, 0, bought, prices, n, dp);
        } else{
            return dp[index][stock][bought] = max(f(index+1, 0, bought, prices, n, dp) + prices[index], f(index+1, 1, bought, prices, n, dp));
        }
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 0, 0, prices, n, dp);
    }
};
