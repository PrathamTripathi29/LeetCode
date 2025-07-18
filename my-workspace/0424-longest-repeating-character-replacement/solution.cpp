class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0;
        int maxcount = 0;
        for(int i=0; i<s.length(); i++){
            count[s[i] - 'A']++;
            maxcount = max(maxcount, count[s[i] - 'A']);
            if(i-left+1-maxcount > k){
                count[s[left] - 'A']--;
                left++;
            }
        }
        return s.length() - left;
    }
};
