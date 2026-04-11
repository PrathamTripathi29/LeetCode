class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<bool> isPrime(100001, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=100000; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=100000; j += i){
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i=0; i<100001; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
        primes.push_back(100003);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(i&1){
                if(isPrime[nums[i]]){
                    if(nums[i] == 2){
                        ans += 2;
                    } else {
                        ans++;
                    }
                }
            } else {
                if(!isPrime[nums[i]]){
                    int nextPrime = 0;
                    auto it = upper_bound(primes.begin(), primes.end(), nums[i]);
                    nextPrime = *it;
                    ans += (nextPrime - nums[i]);
                }
            }
        }
        return ans;
    }
};
