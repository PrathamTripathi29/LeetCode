class Solution {
public:
    int f(int idx, int prev, int n, vector<vector<int>>& dp, string& s){
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1){
            return dp[idx][prev+1];
        } else {
            int keep, del;
            keep = 1e9;
            if(prev == -1 || (s[idx] == 'a' && prev == 0) || (s[idx] == 'b' && prev == 1) || (s[idx] == 'b' && prev == 0)){
                int newPrev;
                if(s[idx] == 'a'){
                    newPrev = 0;
                } else {
                    newPrev = 1;
                }
                keep = f(idx+1, newPrev, n, dp, s);
            }
            del = f(idx+1, prev, n, dp, s) + 1;
            return dp[idx][prev+1] = min(keep, del); 
        }
    }
    int minimumDeletions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return f(0, -1, n, dp, s);
    }
};
