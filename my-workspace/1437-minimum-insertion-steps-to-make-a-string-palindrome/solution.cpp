class Solution {
public:
    int minInsertions(string s) {
        string revs = s;
        reverse(revs.begin(), revs.end());
        int n = s.length();
        vector<int> curr(n+1, 0);
        vector<int> prev(n+1, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i] == revs[j]){
                    curr[j+1] = prev[j] + 1;
                } else{
                    curr[j+1] = max(curr[j], prev[j+1]);
                }
            }
            prev = curr;
        }
        return n - prev[n];
    }
};
