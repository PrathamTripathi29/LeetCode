class Solution {
public:
    int f(vector<int>& nums, int k, int n){
        int l=0;
        int count = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i]&1) count++;
            while(count > k && l <= i){
                if(nums[l]&1) count--;
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        return f(nums, k, n) - f(nums, k-1, n);
    }
};
