class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int left = 0;
        int maxsum = 0;
        int currsum = 0;
        for(int i=0; i<n; i++){
            if(mp.count(nums[i]) && mp[nums[i]] >= left){
                while(left <= mp[nums[i]]){
                    currsum -= nums[left];
                    left++;
                }
            }
            currsum += nums[i];
            mp[nums[i]] = i;
            maxsum = max(maxsum, currsum);
        }
        return maxsum;
    }
};
