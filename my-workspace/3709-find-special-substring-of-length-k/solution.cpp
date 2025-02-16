class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int count = 1;
        char ch = s[0];
        if(s.length() == 1){
            return true;
        }
        for(int i=1; i<s.length(); i++){
            if(k==1 && s[0] != s[1]){
                return true;
            }
            if(s[i] == ch){
                count++;
            }
            else{
                ch = s[i];
                count = 1;
            }
            if(count == k){
                int low, high;
                low = i-k;
                high = i+1;
                bool leftcheck = (low>=0 && s[low] == s[i]);
                bool rightcheck = (high < s.length() && s[high] == s[i]);
                if(!leftcheck && !rightcheck){
                    return true;
                }
            }
                
        }
        return false;
    }
};
