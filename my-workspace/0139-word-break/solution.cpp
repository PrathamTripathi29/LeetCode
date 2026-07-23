class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(string word : wordDict){
                int idx = i - word.length();
                if(idx >= 0 && dp[idx] == true){
                    if(s.substr(idx, word.length()) == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
