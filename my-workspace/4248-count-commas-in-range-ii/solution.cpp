class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        if(n == 1e15){
            commas += 5;
            commas += (1e15 - 1e12)*4;
            commas += (1e12 - 1e9)*3;
            commas += (1e9 - 1e6)*2;
            commas += (1e6 - 1e3);
        }
        else if(n >= 1e12){
            commas += (n - 1e12 + 1)*4;
            commas += (1e12 - 1e9)*3;
            commas += (1e9 - 1e6)*2;
            commas += (1e6 - 1e3);
        }
        else if(n >= 1e9){
            commas += (n - 1e9 + 1)*3;
            commas += (1e9 - 1e6)*2;
            commas += (1e6 - 1e3);
        }
        else if(n >= 1e6){
            commas += (n - 1e6 + 1)*2;
            commas += (1e6 - 1e3);
        }
        else if(n >= 1e3){
            commas += (n - 1e3 + 1);
        }
        return commas;
    }
};
