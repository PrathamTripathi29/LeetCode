class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        mp[sum]++;
        int count = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            count += mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
