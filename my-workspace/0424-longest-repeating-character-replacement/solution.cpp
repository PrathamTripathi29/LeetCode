class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char, int> mp;
        int maxFreq = 0;
        char maxFreqChar;
        int ans = 0;
        int l=0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            if(mp[s[i]] > maxFreq){
                maxFreq = mp[s[i]];
                maxFreqChar = s[i];
            }
            if(i-l+1 - maxFreq > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
