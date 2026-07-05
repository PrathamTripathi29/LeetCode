class Solution {
public:
    bool f(int idx1, int idx2, int slen, int tlen, string& s, string& t, vector<vector<int>>& dp, int replaced){
        if(idx1 == slen) return true;
        if(idx2 == tlen) return false;
        if(dp[idx1][replaced] != -1) return dp[idx1][replaced];
        bool rep = false;
        bool dontRep = false;
        if(s[idx1] != t[idx2]){
            if(replaced != 1)
                rep = f(idx1+1, idx2+1, slen, tlen, s, t, dp, 1);

            dontRep = f(idx1, idx2+1, slen, tlen, s, t, dp, replaced);
        } else {
            return dp[idx1][replaced] = f(idx1+1, idx2+1, slen, tlen, s, t, dp, replaced);
        }
        return dp[idx1][replaced] = rep || dontRep;
    }
    bool canMakeSubsequence(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if(slen > tlen) return false;
        vector<vector<int>> dp(slen, vector<int>(2, -1));
        return f(0, 0, slen, tlen, s, t, dp, 0);
    }
};
