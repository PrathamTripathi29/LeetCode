class Solution {    
public:
    int mod = 1e9 + 7;
    int f(int i, int j, vector<vector<int>> &grid, int dir, vector<vector<vector<int>>> &dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0 && j == 0) return 1;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        else{
            if(grid[i][j] == 1){
                if(dir == 0){
                    return f(i-1, j, grid, 1, dp);
                } else{
                    return f(i, j-1, grid, 0, dp);
                }
            }
            long long moves = 0;
            if(j-1 >= 0) moves += f(i, j-1, grid, 0, dp);
            if(i-1 >= 0) moves += f(i-1, j, grid, 1, dp);

            return dp[i][j][dir] = moves % mod;
        }
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dir;
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(2, -1)));
        int i = r-1, j = c-1;
        return f(i, j, grid, 0, dp);
    }
};
