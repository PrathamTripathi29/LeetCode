class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        int profit = 0;
        for(int price : prices){
            if(price < mn) mn = price;
            profit = max(profit, price-mn);
        }
        return profit;
    }
};
