class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++){
            dp[0][i] = grid[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int currmin = INT_MAX;
                for(int k=0; k<n; k++){
                    if(k == j){
                        continue;
                    }
                    currmin = min(currmin, grid[i][j] + dp[i-1][k]);
                    
                }
                dp[i][j] = currmin;
            }
        }
        int minsum = dp[n-1][0];
        for(int i=1; i<n; i++){
            minsum = min(minsum, dp[n-1][i]);
        }
        return minsum;
    }
};
