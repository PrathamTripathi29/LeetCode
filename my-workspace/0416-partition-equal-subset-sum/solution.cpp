class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum %2 != 0) return false;
        int targetSum = sum/2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;
        for(int num : nums){
            for(int i=targetSum; i>=num; i--){
                if(dp[i-num]) dp[i] = true;
                if(dp[targetSum]) return true;
            }
        }
        return dp[targetSum];
    }
};
