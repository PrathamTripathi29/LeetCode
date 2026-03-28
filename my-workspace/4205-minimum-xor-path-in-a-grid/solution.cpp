class Solution {
public:
    int f(int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n, int XOR){
        if(r >= m || c >= n) return 1e8;
        if(r == m-1 && c == n-1) return XOR^grid[r][c];
        if(dp[r][c][XOR] != -1) return dp[r][c][XOR];
        int right = f(r, c+1, grid, dp, m, n, XOR^grid[r][c]);
        int down = f(r+1, c, grid, dp, m, n, XOR^grid[r][c]);
        return dp[r][c][XOR] = min(right, down);
    }
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return f(0, 0, grid, dp, m ,n, 0);
    }
};
