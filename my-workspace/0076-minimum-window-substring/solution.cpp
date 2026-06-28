class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int count = 0;
        unordered_map<char, int> mp;
        int l = 0;
        int minLen = INT_MAX;
        int st, ed;
        for(char ch : t){
            mp[ch]++;
        }
        for(int i=0; i<n; i++){
            if(mp.count(s[i])){
                if(mp[s[i]] > 0) count++;
                mp[s[i]]--;
            }
            while(count >= t.size() && l <= i){
                if(i-l+1 < minLen){
                    minLen = i-l+1;
                    st = l;
                    ed = i;
                }
                if(mp.count(s[l])){
                    mp[s[l]]++;
                    if(mp[s[l]] > 0) count--;
                }
                l++;
            }
        }
        if(minLen == INT_MAX) return "";
        return s.substr(st, ed-st+1);
    }
};
