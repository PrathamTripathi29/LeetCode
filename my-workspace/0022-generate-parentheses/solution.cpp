class Solution {
public:
    void f(int opp, int clp, string s, int n, vector<string>& ans){
        if(opp == n && clp == n){
            ans.push_back(s);
            return;
        }
        if(opp < n){
            f(opp+1, clp, s+'(', n, ans);
        }
        if(clp < opp){
            f(opp, clp+1, s+')', n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(0, 0, "", n, ans);
        return ans;
    }
};
