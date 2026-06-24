class Solution {
public:
    int f(vector<int>& nums, int k, int n){
        unordered_map<int, int> mp;
        int l=0;
        int ans = 0;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            while(mp.size() > k && l <= i){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return f(nums, k, n) - f(nums, k-1, n);
    }
};
