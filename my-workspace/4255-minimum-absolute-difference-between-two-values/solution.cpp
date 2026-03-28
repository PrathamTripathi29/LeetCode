class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                mp[1].push_back(i);
            }
            if(nums[i] == 2){
                mp[2].push_back(i);
            }
        }
        int ans = INT_MAX;
        if(mp.find(1) == mp.end() || mp.find(2) == mp.end()) return -1;
        for(int idx1 : mp[1]){
            for(int idx2 : mp[2]){
                ans = min(ans, abs(idx1-idx2));
            }
        }
        return ans;
    }
};
