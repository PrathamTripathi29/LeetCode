class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(26, 0);
        vector<bool> present(26, false);
        for(char ch : s){
            freq[ch-'a']++;
        }
        stack<char> st;
        string ans;
        for(char ch : s){
            if(present[ch-'a']){
                freq[ch-'a']--;
                continue;
            }
            if(st.empty()){
                st.push(ch);
                present[ch-'a'] = true;
                freq[ch-'a']--;
                continue;
            }
            while(!st.empty() && st.top() > ch && freq[st.top()-'a'] > 0){
                present[st.top()-'a'] = false;
                st.pop();
            }
            st.push(ch);
            present[ch-'a'] = true;
            freq[ch-'a']--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
