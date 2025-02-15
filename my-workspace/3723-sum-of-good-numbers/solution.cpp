class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            int low, high;
            if(i-k >= 0){
                low = i-k;
            }
            else{
                low = -1;
            }
            if(i+k <= nums.size()-1){
                high = i+k;
            }
            else{
                high = -1;
            }
            if(low == -1 && high == -1){
                sum += nums[i];
            }
            else if(low == -1){
                if(nums[i] > nums[high]){
                    sum += nums[i];
                }
            }
            else if(high == -1){
                if(nums[i] > nums[low]){
                    sum += nums[i];
                }
            }
            else{
                if(nums[i] > nums[low] && nums[i] > nums[high]){
                    sum += nums[i];
                }
            }
        }
        return sum;
    }
};
