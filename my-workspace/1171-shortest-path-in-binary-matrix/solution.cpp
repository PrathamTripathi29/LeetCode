class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        queue<tuple<int, int, int>> pq;
        pq.push({1, 0, 0});
        int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!pq.empty()){
            auto [d, r, c] = pq.front();
            pq.pop();
            if(d > dist[r][c]) continue;
            for(int i=0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0){
                    if(d + 1 < dist[nr][nc]){
                        dist[nr][nc] = d + 1;
                        pq.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }
        return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
    }
};
