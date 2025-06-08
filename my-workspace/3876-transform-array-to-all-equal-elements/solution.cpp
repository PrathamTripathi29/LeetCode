class Solution {
public:
    bool check(vector<int> nums, int k, int val){
        for(int i=0; i<(nums.size() - 1); i++){
            if(nums[i] != val){
                nums[i] *= -1;
                nums[i+1] *= -1;
                k--;
                if(k < 0){
                    return false;
                }
            }
        }
        if(nums[nums.size()-1] == val){
            return true;
        }
        return false;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return check(nums, k, 1) || check(nums, k, -1);
    }
};
