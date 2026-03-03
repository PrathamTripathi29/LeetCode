class Solution {
public:
    char f(int n, int k, bool toInvert){
        if(n==1){
            if(toInvert){
                return '1';
            } else{
                return '0';
            }
        }
        int Sp = (1<<(n-1)) - 1;
        if(k <= Sp){
            return f(n-1, k, toInvert);
        } else if(k == Sp+1){
            if(toInvert){
                return '0';
            } else {
                return '1';
            }
        } else {
            return f(n-1, 2*Sp-k+2, !toInvert);
        }
        
    }
    char findKthBit(int n, int k) {
        return f(n, k, false);
    }
};
