class Solution {
public:
    int digitproduct(int n){
        int product = 1;
        while(n > 0){
            product *= n%10;
            n = n/10;
        }
        return product;
    }
    int digitsum(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    bool checkDivisibility(int n) {
        int digitSum = digitsum(n);
        int digitProduct = digitproduct(n);
        int sum = digitSum + digitProduct;
        return n%sum == 0;
    }
};
