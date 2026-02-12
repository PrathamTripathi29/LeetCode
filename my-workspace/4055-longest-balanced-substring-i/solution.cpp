class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            vector<int> freq(26, 0);
            int distincts = 0;
            int maxFreq = 0;
            for(int j=i; j<n; j++){
                int ch = s[j] - 'a';
                freq[ch]++;
                if(freq[ch] == 1){
                    distincts++;
                }
                maxFreq = max(maxFreq, freq[ch]);
                if(maxFreq * distincts == j-i+1){
                    maxLen = max(j-i+1, maxLen);
                }
            }
        }
        return maxLen;
    }
};
