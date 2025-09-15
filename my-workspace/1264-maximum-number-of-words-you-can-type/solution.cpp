class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        unordered_set<char> S;
        for(int i=0; i<brokenLetters.length(); i++){
            S.insert(brokenLetters[i]);
        }
        stringstream ss(text);
        string word;
        while(ss >> word){
            int flag = 0;
            for(int i=0; i<word.length(); i++){
                if(S.count(word[i])){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                count++;
            }
        }
        return count;
    }
};
