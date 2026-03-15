class Solution {
public:
    int countCommas(int n) {
        int commas;
        if(n < 1000){
            return 0;
        }
        commas = (n - 1000 + 1);
        return commas;
    }
};
