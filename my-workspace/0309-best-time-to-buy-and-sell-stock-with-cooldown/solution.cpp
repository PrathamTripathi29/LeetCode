class Solution {
public:
    // int f(int index, int stock, int n, vector<vector<int>>& dp, vector<int>& prices){
    //     if(index >= n) return 0;
    //     if(dp[index][stock] != -1){
    //         return dp[index][stock];
    //     } else{
    //         if(stock == 0){
    //             return dp[index][stock] = max(f(index+1, 1, n, dp, prices)-prices[index], f(index+1, 0, n, dp, prices));
    //         } else {
    //             return dp[index][stock] = max(f(index+2, 0,n, dp, prices)+prices[index], f(index+1, 1, n, dp, prices));
    //         }
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // return f(0, 0, n, dp, prices);
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        for(int index = n-1; index>=0; index--){
            dp[index][0] = max(dp[index+1][1] - prices[index], dp[index+1][0]);
            dp[index][1] = max(dp[index+2][0] + prices[index], dp[index+1][1]);
        }
        return dp[0][0];
    }
};
