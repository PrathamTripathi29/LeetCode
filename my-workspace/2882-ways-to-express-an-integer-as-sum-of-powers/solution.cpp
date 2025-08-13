class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> nums;
        int num = 1;
        while(n >= (int)pow(num, x)){
            nums.push_back((int)pow(num, x));
            num++;
        }
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            for(int j = n; j>=nums[i]; j--){
                dp[j] = (dp[j] + dp[j-nums[i]]) % mod;
            }
        }
        return dp[n];
    }
};
