class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i=1; i<=len; i++){
            for(auto word : wordDict){
                int idx = i-word.length();
                if(idx >= 0 && dp[idx] == true){
                    string str = s.substr(idx, word.length());
                    if(str == word){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[len];
    }
};
