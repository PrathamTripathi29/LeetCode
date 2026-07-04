class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefixMax(n, 0);
        vector<long long> suffixMax(n, 0);
        prefixMax[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixMax[i] = max(prefixMax[i-1], (long long)nums[i]);
        }
        suffixMax[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffixMax[i] = max(suffixMax[i+1], (long long)nums[i]);
        }
        int l=0;
        long long ans = 0;
        for(int i=k; i<n; i++){
            ans = max(ans, prefixMax[l] + suffixMax[i]);
            l++;
        }
        return ans;
    }
};
