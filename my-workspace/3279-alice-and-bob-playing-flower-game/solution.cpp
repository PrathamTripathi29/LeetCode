class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        int even, odd;
        if(m%2 == 0){
            even = m/2;
            odd = m/2;
        } else{
            even = m/2;
            odd = m/2 + 1;
        }
        for(int i = 1; i<=n; i++){
            if(i % 2 == 0){
                ans += odd;
            } else{
                ans += even;
            }
        }
        return ans;
    }
};
