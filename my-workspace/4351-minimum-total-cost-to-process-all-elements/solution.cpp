class Solution {
public:
    int mod = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        long long curr = k;
        long long n = 0;
        for(int num : nums){
            if(num > curr){
                long long diff = num-curr;
                long long count = ceil((double)diff/k);
                n += count;
                curr += (long long)k*count;
            }
            curr -= num;
        }
        long long ans = (n%mod)*((n+1)%mod)/2;
        ans = ans%mod;
        return ans;
    }
};
