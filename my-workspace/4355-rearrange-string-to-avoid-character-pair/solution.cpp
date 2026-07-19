class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        string ans;
        while(mp[y]){
            ans += y;
            mp[y]--;
        }
        mp.erase(y);
        for(auto it : mp){
            char ch = it.first;
            int freq = it.second;
            while(freq--){
                ans += ch;
            }
        }
        return ans;
    }
};
