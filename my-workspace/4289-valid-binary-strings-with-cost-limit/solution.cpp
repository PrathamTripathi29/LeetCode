class Solution {
public:
    void f(string s, int cost, int n, int k, vector<string>& ans){
        if(s.length() == n){
            if(cost <= k){
                ans.push_back(s);
            }
            return;
        }
        f(s + '0', cost, n, k, ans);
        if(s.size() == 0 || s[s.size()-1] != '1'){
            f(s + '1', cost + s.size(), n, k, ans);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        int cost = 0;
        string s = "";
        vector<string> ans;
        f(s, cost, n, k, ans);
        return ans;
    }
};
