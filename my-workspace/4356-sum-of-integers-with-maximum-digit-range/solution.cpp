class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxRange = 0;
        for(int num : nums){
            int mn = INT_MAX;
            int mx = INT_MIN;
            while(num > 0){
                int dig = num%10;
                mn = min(mn, dig);
                mx = max(mx, dig);
                num /= 10;
            }
            maxRange = max(maxRange, mx-mn);
        }
        int ans = 0;
        for(int num : nums){
            int orinum = num;
            int mn = INT_MAX;
            int mx = INT_MIN;
            while(num > 0){
                int dig = num%10;
                mn = min(mn, dig);
                mx = max(mx, dig);
                num /= 10;
            }
            int range = mx-mn;
            if(orinum == 0) range = 0;
            if(range == maxRange){
                ans += orinum;
            }
        }
        return ans;
    }
};
