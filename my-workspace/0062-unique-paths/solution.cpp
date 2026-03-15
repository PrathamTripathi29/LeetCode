class Solution {
public:
    int f(int x, int y, vector<vector<int>>& dp, int m, int n){
        if(x == m-1 && y == n-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        int right = 0, down = 0;
        if(x < m-1){
            down = f(x+1, y, dp, m ,n);
        }
        if(y < n-1){
            right = f(x, y+1, dp, m, n);
        }
        return dp[x][y] = down + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, dp, m, n);
    }
};
