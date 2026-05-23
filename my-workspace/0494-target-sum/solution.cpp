class Solution {
public:
    int f(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp, int n){
        if(idx == n){
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int notTake = f(idx+1, sum, nums, dp, n);
        int take = 0;
        if(nums[idx] <= sum){
            take = f(idx+1, sum-nums[idx], nums, dp, n);
        }
        return dp[idx][sum] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int arrsum = 0;
        for(auto num : nums){
            arrsum += num;
        }
        if(arrsum < abs(target) || (arrsum + target)%2 != 0) return 0;
        int sum = (arrsum + target)/2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(0, sum, nums, dp, n);
    }
};
