class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        if(n == 1) return 1;
        queue<vector<int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        vector<int> dr = {0, 0, -1, 1, -1, 1, 1, -1};
        vector<int> dc = {-1, 1, 0, 0, -1, 1, -1, 1};
        dist[0][0] = 1;
        q.push({1, 0, 0});
        while(!q.empty()){
            int r = q.front()[1];
            int c = q.front()[2];
            int d = q.front()[0];
            q.pop();
            for(int i = 0; i<8; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0){
                    if(d + 1 < dist[nr][nc]){
                        if(nr == n-1 && nc == n-1) return d+1;
                        q.push({d+1, nr, nc});
                        dist[nr][nc] = d + 1;
                     }
                }
            }
        }
        
        return -1;
    }
};
