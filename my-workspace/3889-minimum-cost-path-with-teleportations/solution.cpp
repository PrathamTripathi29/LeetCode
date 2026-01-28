class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxVal = 0;
        for(vector<int>& row : grid){
            for(int val : row){
                maxVal = max(maxVal, val);
            }
        }
        vector<int> temp(maxVal+1, INT_MAX);
        vector<int> best(maxVal+1);
        temp[grid[m-1][n-1]] = 0;

        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;
                int down = (i < m-1) ? dp[i+1][j] + grid[i+1][j] : INT_MAX;
                int right = (j < n-1) ? dp[i][j+1] + grid[i][j+1] : INT_MAX;
                dp[i][j] = min(down, right);
                if(dp[i][j] != INT_MAX){
                    temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                } 
            }
        }

        for(int t = 0; t < k; t++){
            best[0] = temp[0];
            for(int v=1; v<=maxVal; v++){
                best[v] = min(best[v-1], temp[v]);
            }

            for(int i=m-1; i>=0; i--){
                for(int j=n-1; j>=0; j--){
                    if(i == m-1 && j == n-1) continue;

                    int down = (i < m-1) ? dp[i+1][j] + grid[i+1][j] : INT_MAX;
                    int right = (j < n-1) ? dp[i][j+1] + grid[i][j+1] : INT_MAX;
                    int walkCost = min(down, right);
                    int teleportCost = best[grid[i][j]];
                    dp[i][j] = min(walkCost, teleportCost);
                    if(dp[i][j] != INT_MAX){
                        temp[grid[i][j]] = min(temp[grid[i][j]], dp[i][j]);
                    }
                }
            }
        }
        return dp[0][0];
    }
};
