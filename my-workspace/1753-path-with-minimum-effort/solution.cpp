class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({0, 0, 0});
        int dr[4] = {-1, 0, 0, 1};
        int dc[4] = {0, -1, 1, 0};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()){
            auto [d, r ,c] = pq.top();
            pq.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < m && nc < n && nr >= 0 && nc >= 0){
                    int diff = abs(heights[nr][nc] - heights[r][c]);
                    diff = max(diff, d);
                    if(diff < dist[nr][nc]){
                        dist[nr][nc] = diff;
                        pq.push({diff, nr, nc});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};
