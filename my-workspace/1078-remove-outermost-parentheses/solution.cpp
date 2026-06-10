class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string str;
        int d = 0;
        for(char ch : s){
            if(ch == '('){
                if(d > 0){
                    str += ch;
                }
                d++;
                continue;
            }
            d--;
            if(d > 0){
                str += ch;
            }
        }
        return str;
    }
};
