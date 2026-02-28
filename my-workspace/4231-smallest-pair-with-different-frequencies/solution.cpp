class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        int x = -1;
        int y = -1;
        int idx = 0;
        for(auto it : mp){
            if(idx == 0){
                x = it.first;
                idx = 1;
                continue;
            }
            if(it.second != mp[x]){
                y = it.first;
                return {x, y};
            }
        }
        return {-1, -1};
    }
};
