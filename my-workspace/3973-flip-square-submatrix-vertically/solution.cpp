class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i=y; i<y+k; i++){
            for(int j=0; j<k/2; j++){
                swap(grid[x+j][i], grid[x+k-j-1][i]);
            }
        }
        return grid;
    }
};
