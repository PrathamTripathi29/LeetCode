class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char ch : num){
            if(s.empty() || s.back() <= ch){
                if(s.empty() && ch == '0') continue;
                s.push_back(ch);
            } else {
                while(!s.empty() && k > 0 && s.back() > ch){
                    s.pop_back();
                    k--;
                }
                if(s.empty() && ch == '0') continue;
                s.push_back(ch);
            }
        }
        while(!s.empty() && k--){
            s.pop_back();
        }
        if(s.empty()) s = "0";
        return s;
    }
};
