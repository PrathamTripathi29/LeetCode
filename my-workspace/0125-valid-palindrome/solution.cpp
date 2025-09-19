class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i]) || isalpha(s[i])){
                str += s[i];
            }
        }
        int l = str.length();
        for(int i=0; i<l/2; i++){
            if(tolower(str[i]) != tolower(str[l-1-i])) return false;
        }
        return true;
    }
};
