class Solution {
public:
    void f(int idx, vector<int>& nums, vector<vector<int>>& ans, vector<int> sub){
        ans.push_back(sub);
        for(int i=idx; i<nums.size(); i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            sub.push_back(nums[i]);
            f(i+1, nums, ans, sub);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        f(0, nums, ans, {});
        return ans;
    }
};
