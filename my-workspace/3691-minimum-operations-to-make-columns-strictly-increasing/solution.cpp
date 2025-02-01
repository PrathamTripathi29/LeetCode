class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int operations = 0;
    for(int j=0; j<columns; j++){
        for(int i=0; i<rows-1; i++){
            if(grid[i][j] >= grid[i+1][j]){
                int diff = grid[i][j] - grid[i+1][j];
                grid[i+1][j] += diff + 1;
                operations += diff + 1;
            }
        }
    }
    return operations;
    }
};
