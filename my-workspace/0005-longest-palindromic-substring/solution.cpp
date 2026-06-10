class Solution {
public:
    int f(int l, int r, string& s, int n){
        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        int st = 0;
        int ed = 0;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            int len = max(f(i, i, s, n), f(i, i+1, s, n));
            if(len > maxLen){
                maxLen = len;
                st = i - (maxLen-1)/2;
                ed = i + maxLen/2;
            }
        }
        return s.substr(st, ed-st+1);
    }
};
