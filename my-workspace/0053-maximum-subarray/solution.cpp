class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int currsum = 0;
        for(int num : nums){
            currsum = max(num, currsum+num);
            sum = max(sum, currsum);
        }
        return sum;
    }
};
