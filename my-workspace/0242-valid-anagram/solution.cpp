class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.length() != t.length()){
            return false;
        }
        for(int i = 0; i<s.length(); i++){
            char ch = s[i];
            if(mp.find(ch) == mp.end()){
                mp[ch] = 1;
            }
            else{
                mp[ch]++;
            }
        }
        for(int i = 0; i<t.length(); i++){
            char ch = t[i];
            if(mp.find(ch) == mp.end()){
                return false;
            }
            else{
                mp[ch]--;
            }
            if(mp[ch] < 0){
                return false;
            }
        }
        return true;
    }
};
