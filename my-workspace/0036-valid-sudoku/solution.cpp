class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    continue;
                }
                char num = board[row][col];
                int boxno = row/3 * 3 + col/3;
                if(rows[row].count(num) || cols[col].count(num) || boxes[boxno].count(num)){
                    return false;
                }

                rows[row].insert(num);
                cols[col].insert(num);
                boxes[boxno].insert(num);
            }
        }

        return true;

    }
};
