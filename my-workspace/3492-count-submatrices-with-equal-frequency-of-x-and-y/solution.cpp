class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> xfreq(m, vector<int>(n, 0));
        vector<vector<int>> yfreq(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j == 0){
                    if(grid[i][j] == 'X'){
                        xfreq[i][j] = 1;
                    }
                    if(grid[i][j] == 'Y'){
                        yfreq[i][j] = 1;
                    }
                    continue;
                }
                if(grid[i][j] == 'X'){
                    xfreq[i][j] = xfreq[i][j-1] + 1;
                } else {
                    xfreq[i][j] = xfreq[i][j-1];
                }
                if(grid[i][j] == 'Y'){
                    yfreq[i][j] = yfreq[i][j-1] + 1;
                } else {
                    yfreq[i][j] = yfreq[i][j-1];
                }
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                if(i==0){
                    continue;
                }
                xfreq[i][j] += xfreq[i-1][j];
                yfreq[i][j] += yfreq[i-1][j];
            }
        }
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(xfreq[i][j] > 0 && xfreq[i][j] == yfreq[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
