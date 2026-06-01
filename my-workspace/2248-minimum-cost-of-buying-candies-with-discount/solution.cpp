class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(), cost.rend());
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(i%3 == 0) continue;
            ans += cost[i-1]; 
        }
        return ans;
    }
};
