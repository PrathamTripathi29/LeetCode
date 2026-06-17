class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if(ch == ')'){
                    if(top != '(') return false;
                } else if(ch == '}'){
                    if(top != '{') return false;
                } else {
                    if(top != '[') return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};
