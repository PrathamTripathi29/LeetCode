class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        int size = nums.size();
        for(int i=0; i<size; i++){
            if(i>maxreach){
                return false;
            }
            maxreach = max(maxreach, i + nums[i]);
        }
        if(maxreach >= size-1){
            return true;
        }
        else{
            return false;
        }
    }
};
