class Solution {
public:
    bool consecutiveSetBits(int n) {
        int prevBit = n&1;
        n /= 2;
        int flag = false;
        while(n > 0){
            int bit = n&1;
            if(bit == prevBit && bit == 1){
                if(flag == false){
                    flag = true;
                }
                else {
                    return false;
                }
            }
            prevBit = bit;
            n /= 2;
        }
        return flag;
    }
};
