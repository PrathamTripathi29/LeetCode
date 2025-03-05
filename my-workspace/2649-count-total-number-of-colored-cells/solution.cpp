class Solution {
public:
    long long coloredCells(int n) {
        long long col = 0;
        long long m = n-1;
        col = m*((2*4) + (m-1)*4)/2;
        return col + 1;
    }
};
