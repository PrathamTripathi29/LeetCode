class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int, bool> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%k == 0){
                mp[nums[i]] = true;
            }
        }
        for(int i=k; i<pow(2,31)-1; i += k){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
        return -1;
    }
};
