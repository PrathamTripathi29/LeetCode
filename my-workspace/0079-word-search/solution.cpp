class Solution {
public:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

    bool f(int r, int c, vector<vector<char>>& board, int idx, string& word){
        if(idx == word.length()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
        if(board[r][c] != word[idx]) return false;
        char ch = board[r][c];
        board[r][c] = '#';
        bool flag = false;
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];
            flag = flag || f(nr, nc, board, idx+1, word);
        }
        board[r][c] = ch;
        return flag;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    if(f(i, j, board, 0, word)) return true;
                }
            }
        }
        return false;
    }
};
