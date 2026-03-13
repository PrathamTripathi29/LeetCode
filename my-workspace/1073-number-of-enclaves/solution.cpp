class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[r][c] = 1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                if(grid[nr][nc] == 1){
                    if(!vis[nr][nc])
                        dfs(nr, nc, grid, vis, m, n);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            if(grid[0][i] == 1){
                dfs(0, i, grid, vis, m, n);
            }
            if(grid[m-1][i] == 1){
                dfs(m-1, i, grid, vis, m, n);
            }
        }
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, grid, vis, m, n);
            }
            if(grid[i][n-1] == 1){
                dfs(i, n-1, grid, vis, m, n);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
