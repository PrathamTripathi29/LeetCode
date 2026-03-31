class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto word : wordList){
            words.insert(word);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [word, dist] = q.front();
            if(word == endWord){
                return dist;
            }
            words.erase(word);
            q.pop();
            for(int i=0; i<word.length(); i++){
                char oc = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == oc) continue;
                    word[i] = c;
                    if(words.count(word)){
                        words.erase(word);
                        q.push({word, dist + 1});
                    }
                }
                word[i] = oc;
            }
        }
        return 0;
    }
};
