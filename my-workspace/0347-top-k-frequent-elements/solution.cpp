class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int& num : nums){
            mp[num]++;
        }
        for(auto& it : mp){
            int num = it.first;
            int freq = it.second;
            bucket[freq].push_back(num);
        }
        for(int i=n; i>=0; i--){
            if(bucket[i].empty()) continue;
            for(int j=0; j<bucket[i].size(); j++){
                ans.push_back(bucket[i][j]);
                k--;
                if(k == 0) return ans;
            }
        }
        return {};
    }
};
