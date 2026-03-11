class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis, int m, int n){
        vis[r][c] = 1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                if(!vis[nr][nc] && grid[nr][nc] == '1'){
                    dfs(nr, nc, grid, vis, m, n);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    islands++;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }
        return islands;
    }
};
