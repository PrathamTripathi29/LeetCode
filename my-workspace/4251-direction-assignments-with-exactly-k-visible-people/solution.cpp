class Solution {
public:
    int mod = 1e9+7;
    long long modPow(long long f, long long s){
        long long ans = 1;
        while(s){
            if(s&1){
                ans = (ans*f)%mod;
            }
            f = (f*f)%mod;
            s = s>>1;
        }
        return ans;
    }
    int countVisiblePeople(int n, int pos, int k) {
        if(k == 0 || k == n-1) return 2;
        int totalNoOfPeople = n-1;
        long long ans = 1;
        for(int i=0; i<k; i++){
            ans = (ans*(totalNoOfPeople-i))%mod;
            ans = (ans*modPow(i+1, mod-2))%mod;
        }
        ans = (ans*2)%mod;
        return ans;
    }
};
