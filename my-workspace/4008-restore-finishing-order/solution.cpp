class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n = order.size();
        int f = friends.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int fren : friends){
            mp[fren] = 1;
        }
        for(int num : order){
            if(mp.find(num) != mp.end()){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
