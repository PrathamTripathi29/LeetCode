class Solution {
public:
    string lexSmallest(string s) {
        int k = 1;
        int n = s.length();
        string ans(n, 'z');
        for(int i=1; i<=n; i++){
            string str1 = s; reverse(str1.begin(), str1.begin()+i);
            string str2 = s; reverse(str2.end()-i, str2.end());
            if(str1 < str2){
                if(str1 < ans){
                    ans = str1;
                }
            } else {
                if(str2 < ans){
                    ans = str2;
                }
            }
        }
        return ans;
    }
};
