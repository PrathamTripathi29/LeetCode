class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;
        for(char ch : n){
            int num = ch - '0';
            maxDigit = max(maxDigit, num);
            if(maxDigit == 9) break;
        }
        return maxDigit;
    }
};
