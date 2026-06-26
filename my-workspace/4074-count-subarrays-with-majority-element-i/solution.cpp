class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = 0;
        mp[1] = nums[0] == target ? 1 : 0;
        for(int i=1; i<n; i++){
            if(nums[i] == target){
                mp[i+1] = mp[i] + 1;
            } else {
                mp[i+1] = mp[i];
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int freq = mp[j+1] - mp[i];
                if(freq > (j-i+1)/2){
                    count++;
                }
            }
        }
        return count;
    }
};
