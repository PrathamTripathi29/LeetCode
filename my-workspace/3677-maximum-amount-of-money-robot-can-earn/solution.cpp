class Solution {
public:
    int f(int r, int c, int nt, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int m, int n){
        if(r < 0 || c < 0 || r >= m || c >= n) return -1e8;
        if(r == m-1 && c == n-1){
            if(coins[r][c] >= 0) return coins[r][c];
            else {
                if(nt >= 2) return coins[r][c];
                else{
                    return 0;
                }
            }
        }
        if(dp[r][c][nt] != -1e8) return dp[r][c][nt];
        int downNt = INT_MIN;
        int rightNt = INT_MIN;
        if(coins[r][c] < 0 && nt < 2){
            downNt = f(r+1, c, nt+1, coins, dp, m, n);
            rightNt = f(r, c+1, nt+1, coins, dp, m, n);
        }
        int down = f(r+1, c, nt, coins, dp, m , n) + coins[r][c];
        int right = f(r, c+1, nt, coins, dp, m, n) + coins[r][c];
        return dp[r][c][nt] = max({down, right, downNt, rightNt});
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1e8)));
        return f(0, 0, 0, coins, dp, m, n);
    }
};
