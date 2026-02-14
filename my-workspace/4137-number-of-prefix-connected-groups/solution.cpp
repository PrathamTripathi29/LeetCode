class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(string word : words){
            if(word.length() < k) continue;
            string pref = word.substr(0, k);
            mp[pref]++;
        }
        int ans = 0;
        for(auto& it : mp){
            if(it.second >= 2) ans++;
        }
        return ans;
    }
};
