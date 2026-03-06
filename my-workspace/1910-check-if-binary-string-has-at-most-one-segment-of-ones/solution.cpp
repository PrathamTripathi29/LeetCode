class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        int flag = false;
        int idx = 0;
        while(s[idx] == '1'){
            idx++;
        }
        for(int i=idx; i<n; i++){
            if(s[i] == '1') flag = true;
        }

        return !flag;
    }
};
