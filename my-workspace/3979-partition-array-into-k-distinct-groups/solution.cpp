class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        unordered_map<int, int> mp;
        for(int num : nums) mp[num]++;
        for(int num : nums){
            if(mp[num] > n/k) return false;
        }
        return true;



    }
};
