class Solution {
public:
    int f(int currPos, vector<int>& nums, int target, vector<int>& dp, int n){
        if(currPos == n-1) return 0;
        if(dp[currPos] != -2) return dp[currPos];
        int ans = -1;
        for(int i=currPos+1; i<n; i++){
            if(abs(nums[currPos] - nums[i]) <= target){
                int jumps = f(i, nums, target, dp, n);
                if(jumps != -1){
                    ans = max(ans, jumps+1);
                }
            }
        }
        return dp[currPos] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -2);
        return f(0, nums, target, dp, n);
    }
};
