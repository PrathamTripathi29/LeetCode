class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int l=0;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(mp[s[i]]){
                while(mp[s[i]]){
                    mp[s[l]]--;
                    l++;
                }
            }
            mp[s[i]]++;
            maxLen = max(maxLen, i-l+1);
        }
        return maxLen;
    }
};
