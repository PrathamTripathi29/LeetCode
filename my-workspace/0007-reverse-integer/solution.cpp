class Solution {
public:
    int reverse(int x) {
        long long revx = 0;
        while(x != 0){
            long long digit = x%10;
            revx = revx*10 + digit;
            x = x/10;
        }
        if(revx > INT_MAX || revx < INT_MIN){
            return 0;
        }
        return (int)revx;
    }
};
