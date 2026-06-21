class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for(int cost : costs){
            coins -= cost;
            if(coins < 0) return count;
            count++;
        }
        return count;
    }
};
