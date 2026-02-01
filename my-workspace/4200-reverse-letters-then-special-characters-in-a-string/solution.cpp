class Solution {
public:
    bool isSpecial(char ch){
        if(ch < 'a' || ch > 'z'){
            return true;
        }
        return false;
    }
    string reverseByType(string s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            while(!isSpecial(s[i])){
                i++;
                if(i >= n){
                    break;
                }
            }
            while(!isSpecial(s[j])){
                j--;
                if(j < 0){
                    break;
                }
            }
            if(i <= j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        i=0;
        j=n-1;
        while(i<=j){
            while(isSpecial(s[i])){
                i++;
                if(i >= n){
                    break;
                }
            }
            while(isSpecial(s[j])){
                j--;
                if(j < 0){
                    break;
                }
            }
            if(i <= j){
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};
