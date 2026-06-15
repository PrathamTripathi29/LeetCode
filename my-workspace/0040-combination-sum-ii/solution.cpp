class Solution {
public:
    void f(int idx, vector<int>& can, int target, int currsum, vector<vector<int>>& ans, vector<int> nums){
        if(currsum > target) return;
        if(currsum == target){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<can.size(); i++){
            if(i != idx && can[i] == can[i-1]) continue;
            if(can[i] + currsum > target) break;
            nums.push_back(can[i]);
            f(i+1, can, target, currsum+can[i], ans, nums);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        f(0, candidates, target, 0, ans, {});
        return ans;
    }
};
