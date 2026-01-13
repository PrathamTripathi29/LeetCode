class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[r][c] = 1;
        vector<int> dr = {0, 0, 1, -1};
        vector<int> dc = {-1, 1, 0, 0};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr, nc, m, n, board, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || i == m-1 || j == 0 || j == n-1){
                    if(board[i][j] == 'O'){
                        dfs(i, j, m, n, board, vis);
                    }
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
