class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss, ts;
        ss = ts = 0;
        while(ss < s.size() && ts <t.size()){
            if(s[ss] == t[ts]){
                ss++;
            }
            ts++;
        }
        if(ss == s.size()){
            return true;
        }
        else{
            return false;
        }
    }
};
