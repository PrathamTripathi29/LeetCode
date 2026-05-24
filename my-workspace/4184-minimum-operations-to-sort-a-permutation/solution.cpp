class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mx = n-1;
        int count = 0;
        int idx = -1;
        for(int i=1; i<n; i++){
            int diff = abs(nums[i] - nums[i-1]);
            if(diff > 1){
                count++;
                if(count == 2) return -1;
                idx = i;
            }
        }
        if(idx == -1){
            if(is_sorted(nums.begin(), nums.end())){
                return 0;
            }
            if(is_sorted(nums.begin(), nums.end(), greater<int>())){
                return 1;
            }
        }
        if(nums[idx] == mx){
            if(nums[(idx+1)%n] != 0 && nums[(idx-1+n)%n] != 0) return -1;
            int l = idx;
            int r = n - idx;
            return min(l, r) + 1;
        }
        if(nums[idx] == 0){
            if(nums[(idx+1)%n] != mx && nums[(idx-1+n)%n] != mx) return -1;
            int l = idx;
            int r = n - idx + 2;
            return min(l, r);
        }
        return -1;
    }
};
