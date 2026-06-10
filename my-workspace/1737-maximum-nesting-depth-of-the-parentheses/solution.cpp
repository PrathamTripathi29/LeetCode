class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int d = 0;
        for(char ch : s){
            if(ch == '('){
                d++;
                mx = max(mx, d);
            } else if(ch == ')'){
                d--;
            }
        }
        return mx;
    }
};
