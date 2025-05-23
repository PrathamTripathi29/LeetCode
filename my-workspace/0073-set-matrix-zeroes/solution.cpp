class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> rowcol;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rowcol.push_back({i, j});
                }
            }
        }
        for(int k=0; k<rowcol.size(); k++){
            int i = rowcol[k][0];
            int j = rowcol[k][1];
            for(int a=0; a<matrix.size(); a++){
                matrix[a][j] = 0;
            }
            for(int a=0; a<matrix[0].size(); a++){
                matrix[i][a] = 0;
            }
        }
    }
};
