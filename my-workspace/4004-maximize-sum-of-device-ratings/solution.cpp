class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();
        if(m == 1) return *min_element(units[0].begin(), units[0].end());
        if(n == 1){
            long long ans = 0;
            for(auto unit : units){
                ans += unit[0];
            }
            return ans;
        }
        int globalMin = INT_MAX;
        int globalSecMin = INT_MAX;
        long long ans = 0;
        for(int i=0; i<m; i++){
            int mn = INT_MAX;
            int secmn = INT_MAX;
            for(int j=0; j<n; j++){
                int rating = units[i][j];
                if(rating < mn){
                    secmn = mn;
                    mn = rating;
                }
                else if(rating >= mn && rating < secmn){
                    secmn = rating;
                }
            }
            globalMin = min(globalMin, mn);
            globalSecMin = min(globalSecMin, secmn);
            ans += secmn;
        }
        return ans + globalMin - globalSecMin;
    }
};
