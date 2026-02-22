class Solution {
public:
    int fac(int n){
        if(n == 0) return 1;
        return n*fac(n-1);
    }
    bool isDigitorialPermutation(int n) {
        long long sum = 0;
        unordered_map<int , int> mpn;
        unordered_map<int , int> mps;
        while(n > 0){
            int dig = n%10;
            sum += fac(dig);
            n /= 10;
            mpn[dig]++;
        }
        while(sum > 0){
            int dig = sum%10;
            mps[dig]++;
            sum /= 10;
        }
        for(auto it : mpn){
            int num = it.first;
            int freq = it.second;
            if(mps.find(num) == mps.end() || mps[num] != freq){
                return false;
            }
        }
        if(mpn.size() != mps.size()){
            return false;
        }
        return true;
    }
};
