class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int row = 0;
        while(row < n){
            vector<int> temp;
            int i = row;
            int j = 0;
            while(i < n && j < n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.rbegin(), temp.rend());
            i = row;
            j = 0;
            int idx = 0;
            while(i < n && j < n && idx < temp.size()){
                grid[i][j] = temp[idx];
                idx++;
                i++;
                j++;
            }
            row++;
        }
        int col = 1;
        while(col < n){
            vector<int> temp;
            int i = 0;
            int j = col;
            while(i < n && j < n){
                temp.push_back(grid[i][j]);
                i++;
                j++;
            }
            sort(temp.begin(), temp.end());
            i=0;
            j=col;
            int idx = 0;
            while(i<n && j<n){
                grid[i][j] = temp[idx];
                i++;
                j++;
                idx++;
            }
            col++;
        }
        return grid;
    }
};
