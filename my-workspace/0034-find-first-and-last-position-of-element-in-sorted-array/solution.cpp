class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0;
        int h=n-1;
        int foccur = n, loccur=n;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] >= target){
                h = mid-1;
                foccur = mid;
            } else{
                l = mid + 1;
            }
        }
        l=0;
        h=n-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] > target){
                h = mid-1;
                loccur = mid;
            } else{
                l = mid + 1;
            }
        }
        if(foccur >= n || nums[foccur] != target){
            return {-1, -1};
        }
        return {foccur, loccur-1};
    }
};
