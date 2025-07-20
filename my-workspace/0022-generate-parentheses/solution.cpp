class Solution {
public:
    void dfs(int openpara, int closepara, string s, int n, vector<string> &ans){
        if(openpara == closepara && openpara + closepara == 2*n){
            ans.push_back(s);
            return;
        }
        if(openpara < n){
            dfs(openpara+1, closepara, s + "(", n, ans);
        }
        if(closepara < openpara){
            dfs(openpara, closepara+1, s + ")", n, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0, 0, "", n, ans);
        return ans;
    }
};
