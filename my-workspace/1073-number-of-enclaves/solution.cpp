class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        stack<pair<int,int>> s;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 || j == 0 || i==m-1 || j==n-1){
                    if(grid[i][j] == 1){
                        s.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {1, -1, 0, 0};
        while(!s.empty()){
            int r = s.top().first;
            int c = s.top().second;
            s.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && vis[nr][nc] == 0 && grid[nr][nc] == 1){
                    s.push({nr, nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    ans++;
                }
            }
        }
        return ans;
    }
};
