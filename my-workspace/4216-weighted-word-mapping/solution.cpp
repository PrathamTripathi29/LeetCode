class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        int n = words.size();
        for(string word : words){
            int weight = 0;
            for(char ch : word){
                int idx = ch - 'a';
                weight += weights[idx];
            }
            weight = weight%26;
            char mapchar = 'z' - weight;
            ans.push_back(mapchar);
        }
        return ans;
    }
};
