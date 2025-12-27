class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(int i=0; i<wordList.size(); i++){
            s.insert(wordList[i]);
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        s.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(word == endWord){
                return dist;
            }
            for(int i=0; i<word.length(); i++){
                char oric = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == oric) continue;
                    word[i] = c;
                    if(s.count(word)){
                        s.erase(word);
                        q.push({word, dist+1});
                    }
                }
                word[i] = oric;
            }
        }
        return 0;
    }
};
