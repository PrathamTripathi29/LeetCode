class Solution {
public:
    long long f(int idx, vector<int>& nums, vector<vector<long long>>& dp, int n, int skip){
        if(idx >= n-1) return 0;
        if(dp[idx][skip] != -1) return dp[idx][skip];
        long long maximize = f(idx+2, nums, dp, n, skip) + max(max(nums[idx-1] - nums[idx] + 1, nums[idx+1] - nums[idx] + 1), 0);
        long long dontMaximize = LLONG_MAX;
        if(skip < 1)
            dontMaximize = f(idx+1, nums, dp, n, skip+1);
        return dp[idx][skip] = min(maximize, dontMaximize);
    }
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        if(n%2){
            for(int i = 1; i < n; i += 2){
                if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) continue;
                ans += (max({nums[i-1] - nums[i], nums[i+1] - nums[i], 0}) + 1);
            }
            return ans;
        }
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(1, nums, dp, n, 0);
    }
};
