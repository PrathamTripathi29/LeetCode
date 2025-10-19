class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            if(mp.find(num) == mp.end()){
                mp[num] = 1;
            } else{
                mp[num]++;
            }
        }
        for(auto& it : mp){
            if(it.second%k == 0){
                sum += it.first*it.second;
            }
        }
        return sum;
    }
};
