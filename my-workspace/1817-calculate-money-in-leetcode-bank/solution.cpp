class Solution {
public:
    int totalMoney(int n) {
        if(n <= 7){
            return n*(n+1)/2;
        }
        int weeks;
        int remdays;
        int money;
        weeks = n/7;
        remdays = n%7;
        money = 28*weeks + 7*(weeks-1)*(weeks)/2;
        money += (((weeks + remdays)*(weeks + remdays + 1)/2) - (weeks*(weeks+1)/2));
        return money;
    }
};
