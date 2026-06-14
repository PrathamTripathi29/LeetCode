class Solution {
public:
    bool checkGoodInteger(int n) {
        long long sqsum = 0;
        long long sum = 0;
        while(n>0){
            int d = n%10;
            n /= 10;
            sum += d;
            sqsum += (d*d);
        }
        return (sqsum-sum) >= 50;
    }
};
