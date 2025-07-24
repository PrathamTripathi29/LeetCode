class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++){
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                }
                else if(j == triangle[i].size()-1){
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(triangle[i][j] + dp[i-1][j], triangle[i][j] + dp[i-1][j-1]);
                }
            }
        }
        int minsum = dp[n-1][0];
        for(int i=1; i<n; i++){
            minsum = min(minsum, dp[n-1][i]);
        }
        return minsum;
    }
};
