class Solution {
public:
    int d1[3] = {-1, 0, 1};
    int d2[3] = {-1, 0, 1};
    // int f(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int m, int n){
    //     if(r < 0 || c1 < 0 || c1 >= n || c2 < 0 || c2 >= n) return INT_MIN;
    //     if(r == m) return 0;
    //     if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
    //     int ans = 0;
    //     if(c1 == c2){
    //         for(int i=0; i<3; i++){
    //             for(int j=0; j<3; j++){
    //                 int nc1 = c1 + d1[i];
    //                 int nc2 = c2 + d2[j];
    //                 ans = max(ans, f(r+1, nc1, nc2, grid, dp, m, n) + grid[r][c1]);
    //             }
    //         }
    //     } else {
    //         for(int i=0; i<3; i++){
    //             for(int j=0; j<3; j++){
    //                 int nc1 = c1 + d1[i];
    //                 int nc2 = c2 + d2[j];
    //                 ans = max(ans, f(r+1, nc1, nc2, grid, dp, m, n) + grid[r][c1] + grid[r][c2]);
    //             }
    //         }
    //     }
    //     return dp[r][c1][c2] = ans;
    // }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
        for(int i=0; i<m; i++){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    if(j1 == j2){
                        dp[i][j1][j2] = grid[i][j1];
                    } else {
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                    }
                }
            }
        }
        for(int i=m-2; i>=0; i--){
            for(int j1=0; j1<n; j1++){
                for(int j2=0; j2<n; j2++){
                    int ans = 0;
                    for(int a=0; a<3; a++){
                        for(int b=0; b<3; b++){
                            int nj1 = j1 + d1[a];
                            int nj2 = j2 + d2[b];
                            if(nj1 >= 0 && nj2 >= 0 && nj1 < n && nj2 < n){
                                int val = dp[i+1][nj1][nj2];
                                if(j1 == j2){
                                    val += grid[i][j1];
                                } else {
                                    val += grid[i][j1] + grid[i][j2];
                                }
                                ans = max(ans, val);
                            }
                        }
                        dp[i][j1][j2] = ans;
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
};
