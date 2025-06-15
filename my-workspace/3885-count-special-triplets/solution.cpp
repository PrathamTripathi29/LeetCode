class Solution {
    typedef long long ll;
public:
    int specialTriplets(vector<int>& nums) {
        int m = 1e9 + 7;
        ll ans = 0;
        unordered_map<int, int> mpl, mpr;
        for(auto num : nums){
            mpr[num]++;
        }
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            if(--mpr[num] == 0){
                mpr.erase(num);
            }

            int t = num*2;
            ll countl = (mpl.count(t) ? mpl[t] : 0);
            ll countr = (mpr.count(t) ? mpr[t] : 0);

            ans = (ans + countl*countr) % m;
            mpl[num]++;
        }
        return int(ans);
    }
};
