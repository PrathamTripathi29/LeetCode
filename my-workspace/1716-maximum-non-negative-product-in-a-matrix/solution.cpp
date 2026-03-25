const int MOD=1e9+7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<long long>> dpMin(n,vector<long long>(m));
        vector<vector<long long>> dpMax(n,vector<long long>(m));
        dpMin[0][0]=grid[0][0];
        dpMax[0][0]=grid[0][0];

        for(int i=1;i<n;i++) dpMin[i][0]=dpMax[i][0]=grid[i][0]*dpMin[i-1][0];
        for(int j=1;j<m;j++) dpMin[0][j]=dpMax[0][j]=grid[0][j]*dpMin[0][j-1];

        for(int i=1;i<n;i++) for(int j=1;j<m;j++){
            auto val1=grid[i][j]*dpMin[i-1][j];
            auto val2=grid[i][j]*dpMin[i][j-1];
            auto val3=grid[i][j]*dpMax[i-1][j];
            auto val4=grid[i][j]*dpMax[i][j-1];
            dpMin[i][j]=min({val1,val2,val3,val4});
            dpMax[i][j]=max({val1,val2,val3,val4});
        }

        if(dpMax[n-1][m-1]<0) return -1;
        return dpMax[n-1][m-1]%MOD;
    }
};
