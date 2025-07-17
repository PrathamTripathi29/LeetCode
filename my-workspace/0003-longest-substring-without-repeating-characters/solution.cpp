class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int maxl = 0;
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++){
            if(mp.find(s[i]) == mp.end() || mp[s[i]] < l){
                mp[s[i]] = i;
                maxl = max(maxl, i-l+1);
            } else {
                l = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        return maxl;
    }
};
