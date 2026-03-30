class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freqEven(26, 0);
        vector<int> freqOdd(26, 0);
        if(s1.length() != s2.length()) return false;
        for(int i=0; i<s1.length(); i++){
            if(i&1){
                freqOdd[s1[i] - 'a']++;
                freqOdd[s2[i] - 'a']--;
            } else {
                freqEven[s1[i] - 'a']++;
                freqEven[s2[i] - 'a']--;
            }
        }
        for(int i=0; i<26; i++){
            if(freqEven[i] != 0 || freqOdd[i] != 0) return false;
        }
        return true;
    }
};
