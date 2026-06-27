class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        int ans = 1;
        if(mp[1] > 0)
            ans = mp[1]&1 ? mp[1] : mp[1]-1;
        
        for(auto& it : mp){
            int len = 0;
            int num = it.first;

            int sq = sqrt(num);

            if(sq*sq == num && mp.count(sq) && mp[sq] > 1) continue;

            while((long long)num*num < INT_MAX && mp.count(num) && mp[num] > 1){
                len += 2;
                num *= num;
            }
            ans = max(ans, len + (mp.count(num) ? 1 : -1));
        }
        return ans;
    }
};
