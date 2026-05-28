class Solution {
public:
    struct Node {
        int links[26];
        int idx;
        int len;
        
        Node() {
            memset(links, -1, sizeof(links));
            idx = -1;
            len = INT_MAX;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node());
    }

    void insert(string& word, int index){
        int node = 0;
        int n = word.length();
        if(n < trie[node].len || (n == trie[node].len && index < trie[node].idx)){
            trie[node].len = n;
            trie[node].idx = index;
        }

        for(char ch : word){
            int c = ch-'a';
            if(trie[node].links[c] == -1){
                trie[node].links[c] = trie.size();
                trie.push_back(Node());
            }
            node = trie[node].links[c];
            if(n < trie[node].len || (n == trie[node].len && index < trie[node].idx)){
            trie[node].len = n;
            trie[node].idx = index;
        }
        }
    }

    int search(string& word){
        int node = 0;
        for(char ch : word){
            int c = ch - 'a';
            if(trie[node].links[c] == -1){
                break;
            }
            node = trie[node].links[c];
        }
        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        for(int i=0; i<wordsContainer.size(); i++){
            string word = wordsContainer[i];
            reverse(word.begin(), word.end());
            insert(word, i);
        }
        vector<int> ans;
        for(auto query : wordsQuery){
            reverse(query.begin(), query.end());
            ans.push_back(search(query));
        }
        return ans;
    }
};
