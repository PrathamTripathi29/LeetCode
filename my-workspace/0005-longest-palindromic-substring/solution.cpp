class Solution {
public:
    int checkpalindrome(string s, int l, int r){
        while(l>=0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        for(int i=0; i<s.length(); i++){
            int maxlen = max(checkpalindrome(s, i, i), checkpalindrome(s, i, i+1));
            if(maxlen > end - start){
                start = i - (maxlen-1)/2;
                end = i + maxlen/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};
