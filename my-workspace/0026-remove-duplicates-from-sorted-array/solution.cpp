class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastuniquepos=0;
        int size = nums.size();
        for(int i=1; i<size; i++){
            if(nums[lastuniquepos] != nums[i]){
                lastuniquepos++;
                nums[lastuniquepos] = nums[i];
            }
        }
        return lastuniquepos+1;
    }
};
