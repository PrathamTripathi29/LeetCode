class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        vector<vector<int>> freq(26, vector<int>(n+1, 0));
        freq[s[0]-'a'][1] = 1;
        int ans = 0;
        for(int i=2; i<=n; i++){
            for(int j=0; j<26; j++){
                freq[j][i] = freq[j][i-1];
            }
            freq[s[i-1]-'a'][i]++;
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int mx = INT_MIN;
                int mn = INT_MAX;
                for(int ch=0; ch<26; ch++){
                    int diff = freq[ch][j+1] - freq[ch][i];
                    if(diff > 0){
                        mx = max(mx, diff);
                        mn = min(mn, diff);
                    }
                }
                ans += (mx-mn);
            }
        }
        return ans;
    }
};
