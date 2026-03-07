class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> ops(2, 0);
        for(int i=0; i<n; i++){
            ops[(s[i]^i)&1]++;
        }
        ans = min(ops[0], ops[1]);
        for(int i=0; i<n-1; i++){
            ops[(s[i]^i)&1]--;
            ops[(s[i]^(n+i))&1]++;
            ans = min(ans, min(ops[0], ops[1]));
        }
        return ans;
    }
};
