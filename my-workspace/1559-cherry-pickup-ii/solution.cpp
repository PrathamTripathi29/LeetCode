class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        for(int j1=0; j1<c; j1++){
            for(int j2=0; j2<c; j2++){
                if(j1 == j2){
                    dp[r-1][j1][j2] = grid[r-1][j1];
                } else{
                    dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
                }
            }
        }

        for(int i=r-2; i>=0; i--){
            for(int j1=0; j1<c; j1++){
                for(int j2=0; j2<c; j2++){
                    int maxcherries = 0;
                    for(int k1 = -1; k1<=1; k1++){
                        for(int k2=-1; k2<=1; k2++){
                            if(j1+k1>=0 && j1+k1 <c && j2+k2>=0 && j2+k2 <c){
                                maxcherries = max(maxcherries, dp[i+1][j1+k1][j2+k2]);
                            }
                        }
                    }
                    int currcherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2]; 
                    dp[i][j1][j2] = maxcherries + currcherries;
                }
            }
        }

        return dp[0][0][c-1];
    }
};
