class Solution {
public:
    string mergeCharacters(string s, int k) {
        int n = s.length();
        int i=0;
        while(i < s.length()){
            char ch = s[i];
            int j = i+1;
            while(j < s.length() && j-i <= k){
                if(s[j] == ch){
                    s.erase(j, 1);
                    i = -1;
                    break;
                } else{
                    j++;
                }
            }
            i++;
        }
        return s;
    }
};
