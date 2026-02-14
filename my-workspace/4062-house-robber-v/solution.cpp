class Solution {
public:
    long long f(int idx, int prevHouseRobbed, vector<int>& nums, vector<int>& colors, vector<vector<long long>>& dp, int n){
        if(idx == n) return 0;
        if(dp[idx][prevHouseRobbed] != -1){
            return dp[idx][prevHouseRobbed];
        } else {
            long long skip = f(idx+1, 0, nums, colors, dp, n);
            long long take = 0;
            if(prevHouseRobbed == 0 || colors[idx] != colors[idx-1]){
                take = f(idx+1, 1, nums, colors, dp, n) + nums[idx];
            }
            return dp[idx][prevHouseRobbed] = max(take, skip);
        }
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        int prevHouseRobbed = 0;
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, prevHouseRobbed, nums, colors, dp, n);
    }
};
