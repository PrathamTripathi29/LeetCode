class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] == '1') return false;
        vector<bool> dp(n, false);
        vector<int> jump(n, 0);
        dp[0] = true;
        for(int i=0; i< minJump; i++){
            jump[i] = 1;
        }
        for(int i=minJump; i<n; i++){
            if(s[i] == '0'){
                if(jump[i-minJump] - (i-maxJump <= 0 ? 0 : jump[i-maxJump-1])){
                    dp[i] = true;
                } else {
                    dp[i] = false;
                }
            }
            if(dp[i]) jump[i] = jump[i-1] + 1;
            else jump[i] = jump[i-1];
        }
        return dp[n-1];
    }
};
