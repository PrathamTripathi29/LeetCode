class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        for(int price : prices){    
            if(price > min) profit = max(profit, price-min);
            if(price < min){
                min = price;
            }
        }
        return profit;
    }
};
