class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        string word;
        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            if(ch == ' '){
                if(word.length() > 0){
                    reverse(word.begin(), word.end());
                    ans += word;
                    ans += ' ';
                }
                word = "";
            } else {
                word += ch;
            }
        }
        reverse(word.begin(), word.end());
        ans += word;
        if(ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};
