class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int l = s.length();
        int n = wordDict.size();
        vector<bool> dp(l+1, false);
        dp[0] = true;
        for(int i=1; i<=l; i++){
            for(auto word : wordDict){
                int idx = i - word.length();
                if(idx >= 0 && dp[idx]){
                    string str = s.substr(idx, word.length());
                    if(str == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
