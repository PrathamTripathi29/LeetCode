class Solution {
public:
    int f(int x, int y, vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& dp){
        if(x == m-1 && y == n-1) return 1;
        if(x >= m || y >= n) return 0;
        if(obstacleGrid[x][y] == 1) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int down = f(x+1, y, obstacleGrid, m, n, dp);
        int right = f(x, y+1, obstacleGrid, m , n, dp);
        return dp[x][y] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return f(0, 0, obstacleGrid, m, n, dp);
    }
};
