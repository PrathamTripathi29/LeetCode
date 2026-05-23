class Solution {
public:
    int f(int idx, int amount, vector<int>& coins, vector<vector<int>>& dp, int n){
        if(idx == n){
            if(amount == 0) return 1;
            return 0;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int notTake = f(idx+1, amount, coins, dp, n);
        int take = 0;
        if(coins[idx] <= amount){
            take = f(idx, amount-coins[idx], coins, dp, n);
        }
        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(0, amount, coins, dp, n);
    }
};
