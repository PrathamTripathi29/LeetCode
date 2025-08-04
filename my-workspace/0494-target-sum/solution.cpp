class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        if(sum < abs(target) || (target+sum)%2 != 0) return 0;

        int newtar = (target+sum)/2;

        vector<int> dp(newtar+1, 0);
        dp[0] = 1;
        for(int num : nums){
            for(int i = newtar; i >= num; i--){
                dp[i] += dp[i-num];
            }
        }
        return dp[newtar];

    }
};
