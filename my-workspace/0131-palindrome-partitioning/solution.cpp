class Solution {
public:
    bool check(string& s, int l, int r){
        while(l <= r){
            if(s[l++] != s[r--]){
                return false;
            }
        }
        return true;
    }
    void f(int idx, string& s, vector<string>& par, vector<vector<string>>& ans){
        if(idx == s.length()){
            ans.push_back(par);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(!check(s, idx, i)) continue;
            par.push_back(s.substr(idx, i-idx+1));
            f(i+1, s, par, ans);
            par.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> par;
        f(0, s, par, ans);
        return ans;
    }
};
