class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        set<int, greater<int>> S;
        for(int num : nums){
            if(S.count(num) == 0 && S.size() < k){
                S.insert(num);
            }
        }
        vector<int> ans(S.begin(), S.end());
        return ans;
    }
};
