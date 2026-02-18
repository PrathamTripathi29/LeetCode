class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = -1;
        while(n>0){
            int bit = n&1;
            if(bit == prevBit) return false;
            prevBit = bit;
            n /= 2;
        }
        return true;
    }
};
