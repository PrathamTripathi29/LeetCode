class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> mat(n, vector<int>(m, 0));
        // color, row, column
        int uncol = n*m;
        priority_queue<vector<int>> pq;
        for(auto& v : sources){
            int r = v[0];
            int c = v[1];
            int color = v[2];
            mat[r][c] = color;
            uncol--;
            pq.push({color, r, c});
        }
        if(uncol == 0) return mat;
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        queue<vector<int>> q;
        while(!pq.empty()){
            q.push(pq.top());
            pq.pop();
        }
        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            int color = vec[0];
            int r = vec[1];
            int c = vec[2];
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nc < m && nr >= 0 && nc >= 0 && mat[nr][nc] == 0){
                    mat[nr][nc] = color;
                    uncol--;
                    if(uncol == 0) return mat;
                    q.push({color, nr, nc});
                }
            }
        }
        return {{}};
    }
};
