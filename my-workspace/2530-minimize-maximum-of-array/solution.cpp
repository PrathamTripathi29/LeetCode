class Solution {
public:
    bool check(int mid, vector<int>& nums, int n){
        long long total = 0;
        for(int i=n-1; i>=1; i--){
            if(nums[i] + total > mid){
                long long diff = nums[i] + total - mid;
                total = diff;
            } else {
                total = 0;
            }
        }
        if(total + nums[0] > mid) return false;
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = *max_element(nums.begin(), nums.end());
        while(l <= h){
            int mid = l + (h-l)/2;
            if(check(mid, nums, n)){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
