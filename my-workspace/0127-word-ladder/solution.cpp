class Solution {
public:
    bool diffcheck(string a, string b){
        int diff = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i] != b[i]){
                diff++;
            }
        }
        if(diff > 1){
            return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord == endWord){
            return 1;
        }
        int n = wordList.size();
        bool flag = true;
        unordered_map<string, bool> vis;
        vis[beginWord] = false;
        for(int i=0; i<n; i++){
            if(wordList[i] == endWord){
                flag = false;
            }
            vis[wordList[i]] = false;
        }
        if(flag){
            return 0;
        }

        unordered_map<string, vector<string>> mp;
        
        for(int i=0; i<n; i++){
            if(diffcheck(beginWord, wordList[i])){
                mp[beginWord].push_back(wordList[i]);
            }
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(diffcheck(wordList[i], wordList[j])){
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int currDist = q.front().second;
            vis[word] = true;
            q.pop();
            for(auto it : mp[word]){
                if(!vis[it])
                    q.push({it, currDist+1});
                if(it == endWord)
                    return currDist + 1;
            }
        }
        return 0;
    }
};
