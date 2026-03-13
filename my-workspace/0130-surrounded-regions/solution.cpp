class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n){
        vis[r][c] = 1;
        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                if(board[nr][nc] == 'O'){
                    if(!vis[nr][nc])
                        dfs(nr, nc, board, vis, m, n);
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, board, vis, m, n);
            }
            if(board[m-1][i] == 'O'){
                dfs(m-1, i, board, vis, m, n);
            }
        }
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis, m, n);
            }
            if(board[i][n-1] == 'O'){
                dfs(i, n-1, board, vis, m, n);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
