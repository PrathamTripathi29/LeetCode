class Solution {
public:
    unordered_map<int,int> mp;
    bool isPrime(int n){
        if(n <= 1){
            return false;
        }
        if(n <= 3){
            return true;
        }
        if(n%2 == 0 || n%3 == 0){
            return false;
        }
        for(int i=5; i*i < n; i += 6){
            if(n%i == 0 || n%(i+2) == 0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        for(auto num : nums){
            if(mp.find(num) == mp.end()){
                mp[num] = 1;
            } else{
                mp[num]++;
            }
        }
        for(const auto &pair : mp){
            if(isPrime(pair.second)){
                return true;
            }
        }
        return false;
    }
};
