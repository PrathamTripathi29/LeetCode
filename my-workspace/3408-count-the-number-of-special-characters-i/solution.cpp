class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        int count = 0;
        vector<bool> presl(26, false);
        vector<bool> presu(26, false);
        for(char ch : word){
            if(ch >= 'a'){
                presl[ch-'a'] = true;
            } else {
                presu[ch-'A'] = true;
            }
        }
        for(int i=0; i<26; i++){
            if(presl[i] && presu[i]) count++;
        }
        return count;
    }
};
