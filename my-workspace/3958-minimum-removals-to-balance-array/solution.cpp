class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int l=0;
        for(int i=1; i<n; i++){
            while((long long)nums[i] > (long long)nums[l]*k) l++;
            maxLen = max(maxLen, i-l+1);
        }
        return n - maxLen;
    }
};
