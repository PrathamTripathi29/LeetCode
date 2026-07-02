class Solution {
public:
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        // r, c, health
        queue<tuple<int, int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, 0));
        q.push({0, 0, health-grid[0][0]});
        while(!q.empty()){
            auto [r, c, h] = q.front();
            q.pop();
            if(h < dist[r][c]) continue;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    int nh = h - grid[nr][nc];
                    if(nh > dist[nr][nc]){
                        dist[nr][nc] = nh;
                        q.push({nr, nc, nh});
                    }
                }
            }
        }
        return dist[m-1][n-1] > 0;
    }
};
