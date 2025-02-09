class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int minlength = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;
        while(i<size){
            sum += nums[i];
            while(sum >= target){
                sum -= nums[j];
                minlength = min(i-j+1, minlength);
                j++;
            }
            i++;
        }
        if(minlength == INT_MAX){
            return 0;
        }
        return minlength;
    }
};
