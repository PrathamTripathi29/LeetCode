class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int l = num.length();
        for(int i=0; i<l/2; i++){
            if(num[i] != num[l-1-i]) return false;
        }
        return true;
    }
};
