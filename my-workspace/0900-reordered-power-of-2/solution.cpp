class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int> freq(10, 0);
        int orinum = n;
        while(orinum > 0){
            int digit = orinum%10;
            freq[digit]++;
            orinum /= 10;
        }
        for(int i=0; i<31; i++){
            int num = pow(2, i);
            vector<int> temp(10, 0);
            while(num > 0){
                int digit = num%10;
                temp[digit]++;
                num /= 10;
            }
            if(temp == freq){
                return true;
            }
        }
        return false;
    }
};
