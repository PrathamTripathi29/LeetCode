class Solution {
public:
    long long f(int idx, bool prev, string& s, vector<int>& nums, vector<vector<long long>>& dp, int n){
        if(idx == n) return 0;
        if(dp[idx][prev] != -1) return dp[idx][prev];
        if(s[idx] == '0') return dp[idx][prev] = f(idx+1, false, s, nums, dp, n);
        long long dontMove = f(idx+1, true, s, nums, dp, n) + nums[idx];
        long long move = 0;
        if(prev == false){
            move = f(idx+1, false, s, nums, dp, n) + nums[idx-1];
        }
        return dp[idx][prev] = max(dontMove, move);
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return f(0, true, s ,nums, dp, n);
    }
};
