class Solution {
public:
    struct TrieNode {
        TrieNode* links[10] = {nullptr};
        bool flag = false;
        bool containsKey(char ch){
            return (links[ch - '0'] != nullptr);
        }
        void put(char ch, TrieNode* node){
            links[ch - '0'] = node;
        }
        TrieNode* get(char ch){
            return links[ch - '0'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };

    class Trie {
        private:
        TrieNode* root;
        public:
        Trie(){
            root = new TrieNode();
        }
        void insert(string integer){
            TrieNode* trieNode = root;
            for(int i=0; i<integer.length(); i++){
                if(!trieNode->containsKey(integer[i])){
                    trieNode->put(integer[i], new TrieNode());
                }
                trieNode = trieNode->get(integer[i]);
            }
            trieNode->setEnd();
        }
        int check(string integer){
            TrieNode* trieNode = root;
            int common = 0;
            for(int i=0; i<integer.length(); i++){
                if(!trieNode->containsKey(integer[i])){
                    return common;
                }
                trieNode = trieNode->get(integer[i]);
                common++;
            }
            return common;
        }
    };
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for(int num : arr1){
            string s = to_string(num);
            trie.insert(s);
        }
        int ans = 0;
        for(int num : arr2){
            string s = to_string(num);
            ans = max(ans, trie.check(s));
        }
        return ans;
    }
};
