class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        int maxLen = 0;
        mp[0] = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) sum++;
            else sum--;
            if(mp.find(sum) != mp.end()){
                maxLen = max(maxLen, i-mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};
