class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<vector<int>> dp(sl+1, vector<int>(pl+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<=sl; i++) dp[i][0] = 0;
        for(int i=1; i<= pl; i++){
            int flag = 1;
            for(int k=1; k<=i; k++){
                if(p[k-1] != '*'){
                    flag = 0;
                    break;
                }
            }
            dp[0][i] = flag;
        }
        int j;
        for(int i=1; i<=sl; i++){
            for(j=1; j<=pl; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[sl][pl];
    }
};
