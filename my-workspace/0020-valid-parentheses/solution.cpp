class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        map<char, char> braces;
        braces['('] = ')';
        braces['{'] = '}';
        braces['['] = ']';
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                S.push(s[i]);
            }
            else if(S.empty()){
                return false;
            }
            else{
                if(braces[S.top()] == s[i]){
                    S.pop();
                }
                else{
                    S.push(s[i]);
                }
            }
        }
        if(S.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
