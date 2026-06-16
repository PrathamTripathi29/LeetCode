class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool isPositive = (dividend < 0 == divisor < 0);
        long long a = llabs((long long)dividend);
        long long b = llabs((long long)divisor);
        unsigned int ans = 0;
        while(a >= b){
            int q = 0;
            while(a >= (b<<(q+1))){
                q++;
            }
            ans += (1<<q);
            a = a - (b<<q);
        }
        return isPositive ? ans : -ans;
    }
};
