class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<vector<int>> dp(n+1, vector<int>(budget+1, 0));
        vector<int> divides(n, 0);
        int minPrice = INT_MAX;
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, items[i][1]);
            for(int j=0; j<n; j++){
                if(i==j) continue;
                if(items[j][0]%items[i][0] == 0) divides[i]++;
            }
        }
        for(int i=0; i<n; i++){
            for(int b = 0; b <= budget; b++){
                int c = items[i][1];
                int d = divides[i] + 1;
                if(c <= b)
                    dp[i+1][b] = max(dp[i][b], dp[i][b-c] + d);
                else
                    dp[i+1][b] = dp[i][b];
            }
        }
        int ans = 0;
        for(int i=0; i<=n; i++){
            for(int b=0; b<=budget; b++){
                ans = max(ans, dp[i][b] + (budget-b)/minPrice);
            }
        }
        return ans;
    }
};
