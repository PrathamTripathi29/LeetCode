class Solution {
public:
    void f(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int>& s, int n){
        if(idx == n){
            ans.push_back(s);
            return;
        }
        f(idx+1, nums, ans, s, n);
        s.push_back(nums[idx]);
        f(idx+1, nums, ans, s, n);
        s.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> s;
        f(0, nums, ans, s, n);
        return ans;
    }
};
