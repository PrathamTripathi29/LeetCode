class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        int len = n-k;
        int sum = 0;
        int l = 0;
        int totalSum = 0;
        for(int i=0; i<len; i++){
            sum += nums[i];
            totalSum += nums[i];
        }
        int minSum = sum;
        for(int i=len; i<n; i++){
            totalSum += nums[i];
            sum += nums[i];
            sum -= nums[l];
            l++;
            minSum = min(minSum, sum);
        }
        return totalSum - minSum;
    }
};
