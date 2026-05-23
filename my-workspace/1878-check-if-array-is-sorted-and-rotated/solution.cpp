class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                drops++;
            }
        }
        if(drops == 0){
            return true;
        }
        if(drops > 1){
            return false;
        }
        if(nums[0] >= nums[n-1]){
            return true;
        }
        return false;
    }
};
