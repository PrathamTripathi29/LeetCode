class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        unordered_map<int, int> mpr, mpl;
        long long ans = 0;
        for(int num : nums){
            mpr[num]++;
        }
        for(int i=0; i<n; i++){
            int num = nums[i];
            if(--mpr[num] == 0){
                mpr.erase(num);
            }
            int t = num*2;
            long long countl = (mpl[t] ? mpl[t] : 0);
            long long countr = (mpr[t] ? mpr[t] : 0);
            mpl[num]++;
            ans = (ans + countl*countr)%mod;
        }
        return (int)ans;
    }
};
