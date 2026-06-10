class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        if(t.length() != n) return false;
        vector<int> schar(26, 0);
        for(int i=0; i<n; i++){
            int chars = s[i] - 'a';
            int chart = t[i] - 'a';
            schar[chars]++;
            schar[chart]--;
        }
        for(int i=0; i<26; i++){
            if(schar[i] != 0) return false;
        }
        return true;
    }
};
