class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minval = INT_MAX;
        int maxval = INT_MIN;
        for(int num : nums){
            maxval = max(maxval, num);
            minval = min(minval, num);
        }
        long long ans = ((long long)maxval - minval) * k;
        return ans;
    }
};
