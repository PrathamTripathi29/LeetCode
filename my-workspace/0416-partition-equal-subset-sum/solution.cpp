class Solution {
public:
    bool f(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp, int n){
        if(idx == n-1) return nums[idx] == sum;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        bool take = false;
        if(nums[idx] <= sum){
            take = f(idx+1, sum-nums[idx], nums, dp, n);
        }
        bool notTake = f(idx+1, sum, nums, dp, n);
        return dp[idx][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum%2) return false;
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(0, sum, nums, dp, n);
    }
};
