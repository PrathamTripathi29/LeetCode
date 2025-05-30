class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long N, M, cost=0;
        N = n-k;
        M = m-k;
        if(n-k > 0){
            cost += k*N;
        }
        if(m-k > 0){
            cost += k*M;
        }
        return cost;

    }
};
