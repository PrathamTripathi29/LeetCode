class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n, 1);
        for(int row = 1; row<m; row++){
            vector<int> curr(n,1);
            for(int col = 1; col<n; col++){
                curr[col] = curr[col-1] + prev[col];
            }
            prev = curr;
        }
        return prev[n-1];
    }
};
