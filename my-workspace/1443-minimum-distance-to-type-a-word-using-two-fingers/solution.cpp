class Solution {
public:
    int calcDist(int pos1, int pos2, string& word){
        if(pos2 == -1) return 0;
        int x1 = pos1%6;
        int y1 = pos1/6;
        int x2 = pos2%6;
        int y2 = pos2/6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    int f(int idx, string& word, vector<vector<vector<int>>>& dp, int n, int lpos, int rpos){
        if(idx == n) return 0;
        if(dp[idx][lpos+1][rpos+1] != -1) return dp[idx][lpos+1][rpos+1];
        int curr = word[idx] - 'A';
        int lf = f(idx+1, word, dp, n, curr, rpos) + calcDist(curr, lpos, word);
        int rf = f(idx+1, word, dp, n, lpos, curr) + calcDist(curr, rpos, word);
        return dp[idx][lpos+1][rpos+1] = min(lf, rf);
    }
    int minimumDistance(string word) {
        int n = word.length();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(27, vector<int>(27, -1)));
        return f(0, word, dp, n, -1, -1);
    }
};
