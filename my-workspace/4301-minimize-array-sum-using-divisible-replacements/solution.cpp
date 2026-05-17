class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
        }
        vector<int> mindiv(mx+1);
        for(int i=0; i<=mx; i++){
            mindiv[i] = i;
        }
        set<int> s(nums.begin(), nums.end());
        for(int num : s){
            if(mindiv[num] == num){
                for(int div = num; div <= mx; div += num){
                    if(mindiv[div] == div){
                        mindiv[div] = num;
                    }
                }
            }
        }
        long long ans = 0;
        for(int num : nums){
            ans += mindiv[num];
        }
        return ans;
    }
};
