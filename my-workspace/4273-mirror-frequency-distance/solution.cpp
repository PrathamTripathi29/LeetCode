class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
        }
        int ans = 0;
        for(auto& it : mp){
            char ch = it.first;
            int freq = it.second;
            char m = (ch <= '9') ? ('9' - (ch - '0')) : ('z' - (ch - 'a'));
            int freqm;
            if(mp.find(m) == mp.end()){
                freqm = 0;
            }
            else{
                freqm = mp[m];
                mp[m] = 0;
            } 
            ans += abs(freq - freqm);
            it.second = 0;
        }
        return ans;
    }
};
