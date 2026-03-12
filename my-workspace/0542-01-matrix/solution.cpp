class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        //tuple -> {i, j, dist}
        queue<tuple<int, int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        while(!q.empty()){
            auto [r, c, d] = q.front();
            q.pop();
            dist[r][c] = d;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    if(!vis[nr][nc] && mat[nr][nc] != 0){
                        q.push({nr, nc, d + 1});
                        vis[nr][nc] = 1;
                    }
                }
            }
        }
        return dist;
    }
};
