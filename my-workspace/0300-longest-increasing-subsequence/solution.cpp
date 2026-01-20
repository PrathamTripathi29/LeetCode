class Solution {
public:
    int f(int idx, int prev, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        } else {
            int notTake = f(idx+1, prev, n, nums, dp);
            int take = 0;
            if(prev == -1 || nums[idx] > nums[prev]){
                take = f(idx+1, idx, n, nums, dp) + 1;
            }
            return dp[idx][prev+1] = max(take, notTake);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(0, -1, n, nums, dp);
    }
};
