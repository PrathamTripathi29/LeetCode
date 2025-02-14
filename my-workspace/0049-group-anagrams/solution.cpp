class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        unordered_map<string, vector<string>> mp;
        for(int i = 0; i<strs.size(); i++){
            string sorted_s = strs[i];
            sort(sorted_s.begin(), sorted_s.end());
            mp[sorted_s].push_back(strs[i]);
        }
        for(auto &p : mp){
            group.push_back(p.second);
        }
        return group;
    }
};
