class Solution {
public:
    int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        long long peoplesharingsecret = 0;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            long long newpeoplewithsecret = 0;
            if(i-delay >= 1){
                newpeoplewithsecret = dp[i-delay];
            }
            long long peopleforgetsecret = 0;
            if(i-forget >= 1){
                peopleforgetsecret = dp[i-forget];
            }
            peoplesharingsecret = (peoplesharingsecret + newpeoplewithsecret - peopleforgetsecret + mod)%mod;
            dp[i] = peoplesharingsecret;
        }
        long long ans = 0;
        for(int i=n-forget+1; i<=n; i++){
            ans = (ans + dp[i])%mod;
        }
        return (int)ans;
    }
};
