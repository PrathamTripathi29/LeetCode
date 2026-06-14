class Solution {
public:
    void f(int n, string str, vector<string>& ans){
        if(str.length() == n){
            ans.push_back(str);
            return;
        }
        if(str.empty() || str.back() == '1'){
            f(n, str+'1', ans);
            f(n, str+'0', ans);
        }
        else {
            f(n, str+'1', ans);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        f(n, "", ans);
        return ans;
    }
};
