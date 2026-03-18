class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j==0){
                    grid[i][j] = grid[i][j];
                    continue;
                }
                grid[i][j] += grid[i][j-1];
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(i==0){
                    continue;
                }
                grid[i][j] += grid[i-1][j];
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] <= k){
                    count++;
                }
            }
        }
        return count;
    }
};
