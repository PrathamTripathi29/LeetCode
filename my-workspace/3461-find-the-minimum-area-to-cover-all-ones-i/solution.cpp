class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 1){
                    minx = min(minx, j);
                    miny = min(miny, i);
                    maxx = max(maxx, j);
                    maxy = max(maxy, i);
                }
            }
        }
        return (maxx - minx + 1) * (maxy - miny + 1);
    }
};
