class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        int maxl = 0;
        unordered_map<char,int> mp;
        int left = 0;
        for(int i=0; i<l; i++){
            if(mp.count(s[i]) == 0 || mp[s[i]] < left){
                mp[s[i]] = i;
                maxl = max(maxl, i - left + 1);
            }
            else{
                left = mp[s[i]] + 1;
                mp[s[i]] = i;
            }
        }
        return maxl;
    }
};
