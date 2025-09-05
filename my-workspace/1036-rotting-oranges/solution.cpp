class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int mins = -1;
        int fresh = 0;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int> p = q.front();
                q.pop();
                for(int i=0; i<4; i++){
                    int nr = p.first + dr[i];
                    int nc = p.second + dc[i];
                    if(nr >= 0 && nc >= 0 && nr < r && nc < c && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            mins++;
        }
        return fresh == 0 ? mins : -1;
    }
};
