class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastpos = 1;
        int size = nums.size();
        if(size <= 2){
            return size;
        }
        for(int i=2; i<size; i++){
            if(nums[i] != nums[lastpos-1]){
                lastpos++;
                nums[lastpos] = nums[i];
            }
        }
        return lastpos+1;
    }
};
