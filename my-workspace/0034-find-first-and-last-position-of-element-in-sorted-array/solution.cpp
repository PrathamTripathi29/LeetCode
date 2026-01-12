class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] == target){
                int st = mid;
                int ed = mid;
                while(st >= 0 && nums[st] == target){
                    st--;
                }
                st++;
                while(ed < n && nums[ed] == target){
                    ed++;
                }
                ed--;
                return {st, ed};
            }
            if(target > nums[mid]){
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        return {-1, -1};
    }
};
