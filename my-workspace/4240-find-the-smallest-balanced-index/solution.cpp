class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n, 0);
        vector<long long> suffixProd(n, 1);
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        for(int i = n-2; i >= 0; i--){
            if(nums[i+1] >= LLONG_MAX/suffixProd[i+1]){
                suffixProd[i] = LLONG_MAX;
                continue;
            }
            suffixProd[i] = suffixProd[i+1]*nums[i+1];
        }
        for(int i=0; i<n; i++){
            if(prefixSum[i] == suffixProd[i]){
                return i;
            }
        }
        return -1;
    }
};
