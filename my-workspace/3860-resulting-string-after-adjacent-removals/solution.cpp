class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if((abs(st.top() - s[i]) == 1 || abs(st.top() - s[i]) == 25)){
                st.pop();
            }
            else{
                st.push(s[i]);
            }

        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
