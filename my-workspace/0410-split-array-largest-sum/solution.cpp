class Solution {
public:
    bool check(int mid, vector<int>& nums, int k){
        int p = 1;
        int curr = 0;
        for(int num : nums){
            curr += num;
            if(curr > mid){
                p++;
                curr = num;
            }
        }
        return p <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = nums[0];
        int high = 0;
        for(int num : nums){
            high += num;
            low = max(low, num);
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid, nums, k)){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
