class Solution {
public:
    long long removeZeros(long long n) {
        string str = "";
        long long ans = 0;
        while(n > 0){
            int digit = n%10;
            str = char(digit + '0') + str;
            n /= 10;
        }
        for(int i=0; i<str.length(); i++){
            char c = str[i];
            if(c != '0'){
                ans *= 10;
                ans += int(c - '0');
            }
        }
        return ans;
    }
};
