class Solution {
public:
    void LPS(string& p, vector<int>& lps){
        int len = 0;
        int i=1;
        while(i < p.length()){
            if(p[i] == p[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0){
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool check(string& p, string& w){
        int m = p.length();
        vector<int> lps(m, 0);
        LPS(p, lps);
        int i=0, j=0;
        while(i < w.length()){
            if(w[i] == p[j]){
                i++;
                j++;
            }
            if(j == m) return true;
            else if(i < w.length() && w[i] != p[j]){
                if(j != 0) j = lps[j-1];
                else i++;
            }
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for(string& p : patterns){
            if(check(p, word)) count++;
        }
        return count;
    }
};
