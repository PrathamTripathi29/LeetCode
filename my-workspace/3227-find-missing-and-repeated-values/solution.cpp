class Solution {
public:
    // 1, 2, 3, 4, 5
    // 1, 2, 2, 4, 5
    // ideal - actual = m - d
    // idea2 - actual2 = m2 - d2 = (m+d)(m-d)
    // add = m+d
    // diff = m-d
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0;
        long long sqSum = 0;
        long long idealSum = 0;
        long long idealSqSum = 0;
        int n = grid.size()*grid.size();
        idealSum = (long long)n*(n+1)/2;
        idealSqSum = (long long)n*(n+1)*(2*n+1)/6;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid.size(); j++){
                sum += grid[i][j];
                sqSum += grid[i][j]*grid[i][j];
            }
        }
        long long diff = idealSum - sum;
        long long diff2 = idealSqSum - sqSum;
        long long add = diff2/diff;
        long long m = (add+diff)/2;
        long long d = (add-diff)/2;
        vector<int> ans;
        ans.push_back(d);
        ans.push_back(m);
        return ans;
    }
};
