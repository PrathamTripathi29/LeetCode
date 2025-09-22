class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
            } else {
                mp[nums[i]]++;
            }
        }
        int total = 0;
        int max = INT_MIN;
        for(auto &it : mp){
            if(it.second > max){
                max = it.second;
                total = it.second;
            } else if(it.second == max){
                total += it.second;
            }
        }
        return total;
    }
};
