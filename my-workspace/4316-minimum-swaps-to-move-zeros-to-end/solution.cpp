class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        int count0 = 0;
        for(auto num : nums){
            if(num == 0){
                count0++;
            }
        }
        int swaps = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0 && i < n - count0){
                swaps++;
            }
        }
        return swaps;
    }
};
