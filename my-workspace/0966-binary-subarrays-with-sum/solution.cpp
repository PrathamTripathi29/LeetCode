class Solution {
public:
    int f(vector<int>& nums, int goal, int n){
        int l=0;
        int sum = 0;
        int subarrs = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            while(sum > goal && l <= i){
                sum -= nums[l];
                l++;
            }
            subarrs += i-l+1;
        }
        return subarrs;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return f(nums, goal, n) - f(nums, goal-1, n);
    }
};
