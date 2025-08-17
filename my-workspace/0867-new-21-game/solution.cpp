class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if( k == 0 || k-1+maxPts <= n) return 1.0;
        vector<double> dp(n+1, 0.0);
        dp[0] = 1.0;
        double currsum = 1.0;
        double finalprob = 0.0;
        for(int i = 1; i<=n; i++){
            dp[i] = currsum/maxPts;

            if(i<k){
                currsum += dp[i];
            } else{
                finalprob += dp[i];
            }
            if(i >= maxPts){
                currsum -= dp[i - maxPts];
            }
        }
        return finalprob;
    }
};
