class Solution {
public:
    int minOperations(string s) {
        string str = s;
        string str2 = s;
        int n = str.length();
        if(n == 1){
            return 0;
        }
        if(n == 2){
            if(s[0] > s[1]){
                return -1;
            }
        }
        sort(str.begin(), str.begin() + n-1);
        int ans1 = 0;
        if(s.substr(0, n-1) != str.substr(0, n-1)){
            ans1++;
        }
        if(str[n-1] < str[n-2]){
            ans1++;
        }
        sort(str.begin()+1, str.end());
        if(str[0] > str[1]){
            ans1++;
        }
        int ans2 = 0;
        sort(str2.begin()+1, str2.end());
        if(s.substr(1, n) != str2.substr(1, n)){
            ans2++;
        }
        if(str2[0] > str2[1]){
            ans2++;
        }
        sort(str2.begin(), str2.begin() + n-1);
        if(str2[n-1] < str2[n-2]){
            ans2++;
        }
        
        return min(ans1, ans2);
    }
};
