class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        int cursum = 0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            sum += nums[i];
        }
        sort(nums.rbegin(), nums.rend());
        for(int i=0; i<size; i++){
            cursum += nums[i];
            ans.push_back(nums[i]);
            if(cursum>(sum-cursum)){
                return ans;
            }
        }
        return ans;

    }
};
