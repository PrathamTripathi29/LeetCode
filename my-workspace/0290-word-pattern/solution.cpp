class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        istringstream stream(s);
        unordered_map<string,char> ptos;
        unordered_map<char,string> stop;
        int i = 0;
        
        while(stream >> word){
            if(i >= pattern.size()){
                return false;
            }
            char ch = pattern[i];
            if(stop.count(ch) && stop[ch] != word){
                return false;
            }
            if(ptos.count(word) && ptos[word] != ch){
                return false;
            }
            stop[ch] = word;
            ptos[word] = ch;
            i++;
        }

        return i == pattern.size();
    }
};
