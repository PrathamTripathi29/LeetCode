class Solution {
public:
    // int f(int index, int stock, int bought, int n, int k, vector<vector<vector<int>>>& dp, vector<int>& prices){
    //     if(index == n){
    //         return 0;
    //     }
    //     if(dp[index][stock][bought] != -1){
    //         return dp[index][stock][bought];
    //     } else{
    //         if(stock == 0){
    //             if(bought < k){
    //                 return dp[index][stock][bought] = max(f(index+1, 1, bought+1, n, k, dp, prices) - prices[index], f(index+1, 0, bought, n, k, dp, prices));
    //             } else{
    //                 return dp[index][stock][bought] = f(index+1, 0, bought, n, k, dp, prices);
    //             }
    //         } else {
    //             return dp[index][stock][bought] = max(f(index+1, 0, bought, n, k, dp, prices) + prices[index], f(index+1, 1, bought, n, k, dp, prices));
    //         }
    //     }
    // }
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return f(0, 0, 0, n, k, dp, prices);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int index = n-1; index >= 0; index--){
            for(int bought = 0; bought<k; bought++){
                dp[index][0][bought] = max(dp[index+1][1][bought+1] - prices[index], dp[index+1][0][bought]);
                dp[index][1][bought] = max(dp[index+1][0][bought] + prices[index], dp[index+1][1][bought]);
            }
            dp[index][0][k] = dp[index+1][0][k];
            dp[index][1][k] = max(dp[index+1][0][k] + prices[index], dp[index+1][1][k]);
        }
        return dp[0][0][0];
    }
};
