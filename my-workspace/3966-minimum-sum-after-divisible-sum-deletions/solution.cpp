class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n+1, 0);
        unordered_map<int, int> mp{{0, n}};
        int prefix = 0;
        for(int i=n-1; i>=0; i--){
            prefix = (prefix + nums[i]) % k;
            dp[i] = nums[i] + dp[i+1];
            if(mp.count(prefix)){
                dp[i] = min(dp[i], dp[mp[prefix]]);
            }
            mp[prefix] = i;
        }
        return dp[0];
    }
};
