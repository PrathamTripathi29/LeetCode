class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operations = 0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                continue;
            }
            else{
                int diff = nums[i-1] - nums[i];
                nums[i] = nums[i] + diff + 1;
                operations = operations + diff + 1;
            }
        }
        return operations;
    }
};
