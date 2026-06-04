class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[pos]){
                pos++;
                nums[pos] = nums[i];
            }
        }
        return pos+1;
    }
};
