class Solution {
public:
    // int f(int r, int c, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n){
    //     if(c < 0 || c >= n) return 1e8;
    //     if(r == n-1) return matrix[r][c];
    //     if(dp[r][c] != -1) return dp[r][c];
    //     int downleft = f(r+1, c-1, matrix, dp, n) + matrix[r][c];
    //     int down = f(r+1, c, matrix, dp, n) + matrix[r][c];
    //     int downright = f(r+1, c+1, matrix, dp, n) + matrix[r][c];
    //     return dp[r][c] = min({downleft, down, downright});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n+2, 1e8));
        // vector<int> ans(n);
        // int mn = INT_MAX;
        // for(int i=0; i<n; i++){
        //     ans[i] = f(0, i, matrix, dp, n);
        //     mn = min(mn, ans[i]);
        // }
        // return mn;
        for(int i=0; i<n; i++){
            dp[0][i+1] = matrix[0][i];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j+1] = min({dp[i-1][j], dp[i-1][j+1], dp[i-1][j+2]}) + matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            ans = min(ans, dp[n-1][i+1]);
        }
        return ans;
    }
};
