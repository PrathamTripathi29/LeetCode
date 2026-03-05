class Solution {
public:
    int minOperations(string s) {
        string oris = s;
        int n = s.length();
        int ans1 = 0, ans0 = 0;
        if(s[0] == '1'){
            for(int i=1; i<n; i++){
                if(s[i] == s[i-1]){
                    s[i] = (s[i] == '0') ? '1' : '0';
                    ans1++;
                }
            }
            oris[0] = '0';
            ans0++;
            for(int i=1; i<n; i++){
                if(oris[i] == oris[i-1]){
                    oris[i] = (oris[i] == '0') ? '1' : '0';
                    ans0++;
                }
            }
        } else {
            for(int i=1; i<n; i++){
                if(s[i] == s[i-1]){
                    s[i] = (s[i] == '0') ? '1' : '0';
                    ans0++;
                }
            }
            oris[0] = '1';
            ans1++;
            for(int i=1; i<n; i++){
                if(oris[i] == oris[i-1]){
                    oris[i] = (oris[i] == '0') ? '1' : '0';
                    ans1++;
                }
            }
        }
        return min(ans1, ans0);
    }
};
