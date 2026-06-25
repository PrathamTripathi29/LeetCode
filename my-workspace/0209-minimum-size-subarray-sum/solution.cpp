class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int minLen = INT_MAX;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum >= target && l <= i){
                minLen = min(minLen, i-l+1);
                sum -= nums[l];
                l++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};
