class Solution {
public:
    void f(int idx, vector<int>& candidates, int target, int currsum, vector<vector<int>>& ans, vector<int> nums){
        if(currsum > target) return;
        if(currsum == target){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<candidates.size(); i++){
            nums.push_back(candidates[i]);
            f(i, candidates, target, currsum+candidates[i], ans, nums);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        f(0, candidates, target, 0, ans, {});
        return ans;
    }
};
