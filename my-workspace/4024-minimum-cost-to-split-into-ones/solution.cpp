class Solution {
public:
    int minCost(int n) {
        int cost = 0;
        cost = n*(n-1)/2;
        return cost;
    }
};
