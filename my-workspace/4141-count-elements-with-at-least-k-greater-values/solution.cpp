class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        set<int, greater<int>> s;
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[num]++;
        }
        for(int num : nums){
            s.insert(num);
        }
        int size = s.size();
        int ans = 0;
        int count = 0;
        for(int num : s){
            if(count >= k) ans += mp[num];
            count += mp[num];
        }
        return ans;
    }
};
