class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 1e18));
        for(int i=0; i<m; i++){
            dp[0][i] = 0;
        }
        for(int j=1; j<=m; j++){
            int pos = factory[j-1][0];
            int limit = factory[j-1][1];
            for(int i=0; i<=n; i++){
                dp[i][j] = dp[i][j-1];
                long long dist = 0;
                for(int k=1; k<=limit && i-k >= 0; k++){
                    dist += abs(robot[i-k] - pos);
                    dp[i][j] = min(dp[i][j], dp[i-k][j-1] + dist);
                }
            }
        }
        return dp[n][m];
    }
};
