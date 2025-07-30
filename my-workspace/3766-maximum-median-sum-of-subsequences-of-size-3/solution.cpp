class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a=0, b=n-2, c=n-1;
        long long sum = 0;
        for(int i=0; i<n/3; i++){
            sum += nums[b];
            b -= 2;
        }
        return sum;
    }
};
