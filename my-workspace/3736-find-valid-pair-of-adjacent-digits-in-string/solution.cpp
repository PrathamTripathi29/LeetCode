class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char,int> mp;
        string ans = "";
        int l = s.length();
        for(int i=0; i<l; i++){
            char a = s[i];
            if(mp.find(a) == mp.end()){
                mp[a] = 1;
            }
            else{
                mp[a]++;
            }
        }
        for(int i=0; i<l-1; i++){
            char a = s[i];
            char b = s[i+1];
            if(mp[a] == int(a - '0') && mp[b] == int(b - '0') && a != b){
                ans += a;
                ans += b;
                return ans;
            }
        }
        return "";
    }
};
