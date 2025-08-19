class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long subarrays = 0;
        long long currsub = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                currsub++;
            } else{
                subarrays += (currsub * (currsub+1))/2;
                currsub = 0;
            }
        }
        subarrays += (currsub * (currsub+1))/2;
        return subarrays;
    }
};
