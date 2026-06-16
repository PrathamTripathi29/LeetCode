class Solution {
public:
    void f(vector<string>& board, int r, int n, vector<vector<string>>& sols){
        if(r == n){
            sols.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(isSafe(board, r, c, n)){
                board[r][c] = 'Q';
                f(board, r+1, n, sols);
                board[r][c] = '.';
            }
        }
    }
    bool isSafe(vector<string>& board, int r, int c, int n){
        for(int i=0; i<n; i++){
            if(board[i][c] == 'Q') return false;
            if(r-i >= 0 && c-i>=0 && board[r-i][c-i] == 'Q') return false;
            if(r-i >=0 && c+i<n && board[r-i][c+i] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sols;
        vector<string> board(n, string(n, '.'));
        f(board, 0, n, sols);
        return sols;
    }
};
