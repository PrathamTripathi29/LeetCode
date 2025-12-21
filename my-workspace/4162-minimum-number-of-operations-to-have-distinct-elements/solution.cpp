class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int last_valid_index = 0;
        for(int i=n-1; i>=0; i--){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                last_valid_index = i+1;
                break;
            }
        }
        int ops = (last_valid_index+2)/3;
        return ops;
    }
};
