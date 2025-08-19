class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        if(n == 1) return nums[0];
        for(int num : nums){
            if(mp.count(num)){
                if(++mp[num] > n/2) return num;
            } else{
                mp[num] = 1;
            }
        }
        return -1;
    }
};
