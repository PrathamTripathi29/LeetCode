class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastpos = 2;
        int size = nums.size();
        if(size <= 2){
            return size;
        }
        for(int i=2; i<size; i++){
            if(nums[i] != nums[lastpos-2]){
                nums[lastpos] = nums[i];
                lastpos++;
            }
        }
        return lastpos;
    }
};
