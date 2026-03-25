class Solution {
public:
    int mod = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        long long prefMul = 1;
        long long suffixMul = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans[i][j] = prefMul;
                prefMul = (prefMul*grid[i][j])%mod;
            }
        }
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                ans[i][j] = (ans[i][j]*suffixMul)%mod;
                suffixMul = (suffixMul*grid[i][j])%mod;
            }
        }
        return ans;
        
    }
};
