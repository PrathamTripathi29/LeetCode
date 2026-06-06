class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int currsum = 0;
        for(int num : nums){
            if(currsum + num < num) currsum = num;
            else currsum += num;
            sum = max(sum, currsum);
        }
        return sum;
    }
};
