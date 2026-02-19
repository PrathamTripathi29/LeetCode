class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i=0; i<n-1; i++){
            char ch1 = s[i];
            char ch2 = s[i+1];
            if(ch1 != ch2){
                int idx1 = i;
                int idx2 = i+1;
                while(idx1 >= 0 && idx2 < n){
                    if(s[idx1] == ch1 && s[idx2] == ch2){
                        count++;
                        idx1--;
                        idx2++;
                    } else{
                        break;
                    }
                }
            }
        }
        return count;
    }
};
