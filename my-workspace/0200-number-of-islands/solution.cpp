class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>> &grid, vector<vector<int>> &v){
        v[i][j] = 1;
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
                for(int k = 0; k<4; k++){
                    
                        int currrow = i + dr[k];
                        int currcol = j + dc[k];
                        if(currrow >= 0 && currcol >= 0 && currrow < m && currcol < n && grid[currrow][currcol] == '1' && !v[currrow][currcol]){
                            dfs(currrow, currcol, m, n, grid, v);
                        }
                    
                }
            
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> v(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && v[i][j] == 0){
                    count++;
                    dfs(i, j, m, n, grid, v);
                }
            }
        }
        return count;
    }
};
