class Solution {
public:
    int f(int col, int prev, vector<vector<int>>& grid, vector<vector<int>>& cost, vector<vector<int>>& dp, int n){
        if(col == n) return 0;
        if(prev != -1 && dp[col][prev] != -1) return dp[col][prev];
        int minOps = INT_MAX;
        for(int target = 0; target < 10; target++){
            if(target == prev) continue;
            int ops = cost[col][target] + f(col+1, target, grid, cost, dp, n);
            minOps = min(minOps, ops);
        }
        if(prev != -1) dp[col][prev] = minOps;
        return minOps;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mp(n, vector<int>(10));
        vector<vector<int>> cost(n, vector<int>(10));
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                mp[j][grid[i][j]]++;
            }
        }
        for(int j=0; j<n; j++){
            for(int target = 0; target < 10; target++){
                cost[j][target] = m - mp[j][target];
            }
        }
        vector<vector<int>> dp(n+1, vector<int>(10, -1));
        return f(0, -1, grid, cost, dp, n);
    }
};
