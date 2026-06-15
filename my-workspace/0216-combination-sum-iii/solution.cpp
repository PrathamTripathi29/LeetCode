class Solution {
public:
    void f(int num, int k, int n, int currsum, vector<int> comb, vector<vector<int>>& ans){
        if(currsum > n) return;
        if(comb.size() > k) return;
        if(currsum == n && comb.size() == k) ans.push_back(comb);
        for(int i=num+1; i<10; i++){
            comb.push_back(i);
            f(i, k, n, currsum+i, comb, ans);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        for(int i=1; i<10; i++)
            f(i, k, n, i, {i}, ans);
        return ans;
    }
};
