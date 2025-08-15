class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int currsum = 0;
        for(int num : nums){
            if(currsum < 0) currsum = 0;
            currsum += num;
            sum = max(sum, currsum);
        }
        return sum;
    }
};
