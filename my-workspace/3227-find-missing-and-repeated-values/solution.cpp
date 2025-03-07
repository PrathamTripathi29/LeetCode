class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long k = n*n;
        long long ess = k * (k + 1) * (2*k + 1) / 6;
        long long es = k * (k + 1) / 2;
        long long ass = 0, as = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                as += grid[i][j];
                ass += grid[i][j] * grid[i][j];
            }
        }
        int r, m;
        r = ((ess - ass)/(es - as) - (es - as))/2;
        m = (es - as) + r;
        vector<int> ans;
        ans.push_back(r);
        ans.push_back(m);
        return ans;
    }
};
