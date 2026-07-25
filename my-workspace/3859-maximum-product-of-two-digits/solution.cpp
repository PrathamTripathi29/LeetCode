class Solution {
public:
    int maxProduct(int n) {
        int mx = 0;
        int secmx = 0;
        while(n > 0){
            int d = n%10;
            if(d > mx){
                secmx = mx;
                mx = d;
            } else if(d > secmx) secmx = d;
            n /= 10;
        }
        return mx*secmx;
    }
};
