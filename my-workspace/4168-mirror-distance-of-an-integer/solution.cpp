class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int ori = n;
        while(n > 0){
            rev *= 10;
            rev += n%10;
            n /= 10;
        }
        return abs(ori - rev);
    }
};
