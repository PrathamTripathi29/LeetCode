class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto word : words){
            int w = 0;
            for(char ch : word){
                w = (w + weights[ch-'a'])%26;
            }
            ans += 'z'-w;
        }
        return ans;
    }
};
