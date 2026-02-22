class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int , int> mp;
        int occurence = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == x){
                mp[++occurence] = i;
            }
        }
        vector<int> ans;
        for(int query : queries){
            if(mp.find(query) == mp.end()) ans.push_back(-1);
            else ans.push_back(mp[query]);
        }
        return ans;
    }
};
