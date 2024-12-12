class Solution {
public:
    bool isPalindrome(string s) {
        string checkpalin = "";
        for(int i=0; i<s.length(); i++){
            if(isalnum(s.at(i))){
                if(isdigit(s.at(i))){
                    checkpalin += s.at(i);
                }
                else{
                    checkpalin += tolower(s.at(i));
                }
            }
        }
        int len;
        len = checkpalin.length();
        for(int i=0; i<len/2; i++){
            if(checkpalin.at(i) != checkpalin.at(len-1-i)){
                return false;
            }
        }
        return true;
    }
};
