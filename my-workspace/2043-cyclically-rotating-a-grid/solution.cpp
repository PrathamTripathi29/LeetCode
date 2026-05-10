class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(m/2, n/2);

        for(int i=0; i<layers; i++){
            int rows = m - i*2;
            int cols = n - i*2;
            int size = 2*rows + 2*(cols-2);
            int rot = k%size;
            vector<int> nums(size);
            vector<int> rotnums(size);
            int idx = 0;
            for(int c=0; c<cols-1; c++){
                nums[idx] = grid[i][i+c];
                idx++;
            }
            for(int r=0; r<rows-1; r++){
                nums[idx] = grid[i+r][n-1-i];
                idx++;
            }
            for(int c=0; c<cols-1; c++){
                nums[idx] = grid[m-1-i][n-1-i-c];
                idx++;
            }
            for(int r=0; r<rows-1; r++){
                nums[idx] = grid[m-1-i-r][i];
                idx++;
            }
            for(int j=0; j<size; j++){
                rotnums[j] = nums[(j+rot)%size];
            }
            idx=0;
            for(int c=0; c<cols-1; c++){
                grid[i][i+c] = rotnums[idx];
                idx++;
            }
            for(int r=0; r<rows-1; r++){
                grid[i+r][n-1-i] = rotnums[idx];
                idx++;
            }
            for(int c=0; c<cols-1; c++){
                grid[m-1-i][n-1-i-c] = rotnums[idx];
                idx++;
            }
            for(int r=0; r<rows-1; r++){
                grid[m-1-i-r][i] = rotnums[idx];
                idx++;
            }
        }
        return grid;
    }
};
