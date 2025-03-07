class Solution {
public:
    bool isprime(int num){
        if(num < 2){
            return false;
        }
        for(int i=2; i*i<= num; i++){
            if(num%i == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes;
        for(int i=left; i<=right; i++){
            if(isprime(i)){
                primes.push_back(i);
            }
        }
        int diff = INT_MAX;
        vector<int> ans(2, -1);
        if(primes.size() < 2){
            return ans;
        }
        for(int i=0; i<primes.size()-1; i++){
            if(primes[i+1] - primes[i] < diff){
                diff = primes[i+1] - primes[i];
                ans[0] = primes[i];
                ans[1] = primes[i+1];
            }
        }
        return ans;
    }
};
