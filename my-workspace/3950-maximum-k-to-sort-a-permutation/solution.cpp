class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n;
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                k = min(k, nums[i] & i);
            }
        }
        return k == n ? 0 : k;
    }
};
