class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = -1;
        int fresh = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }  
                if(grid[i][j] == 1){
                    fresh++;
                } 
            }
        }
        if(fresh == 0) return 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int, int> orange = q.front();
                q.pop();
                int dr[4] = {1, -1, 0, 0};
                int dc[4] = {0, 0, 1, -1};
                for(int i=0; i<4; i++){
                    int nr = orange.first + dr[i];
                    int nc = orange.second + dc[i];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                        if(grid[nr][nc] == 1){
                            grid[nr][nc] = 2;
                            q.push({nr, nc});
                            fresh--;
                        }
                    }
                }
            }
            ans++;
        }
        if(fresh){
            return -1;
        }
        return ans;
    }
};
