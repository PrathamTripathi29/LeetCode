class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;
        long long mul = 1;
        while(n > 0){
            int d = n%10;
            sum += d;
            if(d != 0){
                x = x + d*mul;
                mul *= 10;
            }
            n /= 10;
        }
        return sum*x;
    }
};
