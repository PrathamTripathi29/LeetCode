class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int i = start;
        int j = start;
        int n = nums.size();
        while(i >= 0 || j < n){
            if(i >= 0 && nums[i] == target) return abs(i - start);
            if(j < n && nums[j] == target) return abs(j - start);
            i--;
            j++;
        }
        return 0;
    }
};
