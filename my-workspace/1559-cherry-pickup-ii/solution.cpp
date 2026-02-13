class Solution {
public:
    vector<int> dc1 = {-1, 0, 1};
    vector<int> dc2 = {-1, 0, 1};
    int f(int r, int c1, int c2, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int m, int n){
        if(r == m) return 0;
        if(r < 0) return 0;
        if(c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return 0;
        if(dp[r][c1][c2] != -1){
            return dp[r][c1][c2];
        } else {
            if(c1 == c2){
                int maxVal = 0;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        int nc1 = c1+dc1[i];
                        int nc2 = c2+dc2[j];
                        maxVal = max(maxVal, f(r+1, nc1, nc2, dp, grid, m, n));
                    }
                }
                return dp[r][c1][c2] = maxVal + grid[r][c1];
            } else {
                int maxVal = 0;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        int nc1 = c1+dc1[i];
                        int nc2 = c2+dc2[j];
                        maxVal = max(maxVal, f(r+1, nc1, nc2, dp, grid, m, n));
                    }
                }
                return dp[r][c1][c2] = maxVal + grid[r][c1] + grid[r][c2];
            }
        }
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0, 0, n-1, dp, grid, m, n);
    }
};
