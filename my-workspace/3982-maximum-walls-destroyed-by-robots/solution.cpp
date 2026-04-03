class Solution {
public:
    int countWalls(vector<int>& walls, int l, int u){
        if(l > u) return 0;
        auto it1 = lower_bound(walls.begin(), walls.end(), l);
        auto it2 = upper_bound(walls.begin(), walls.end(), u);
        return it2 - it1;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> roboDist(n);
        for(int i=0; i<n; i++){
            roboDist[i] = {robots[i], distance[i]};
        }
        sort(roboDist.begin(), roboDist.end());
        sort(walls.begin(), walls.end());
        roboDist.push_back({1e9, 0});
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = countWalls(walls, roboDist[0].first - roboDist[0].second, roboDist[0].first);
        if(n > 1)
        dp[0][1] = countWalls(walls, roboDist[0].first, min(roboDist[0].first + roboDist[0].second, roboDist[1].first - 1));
        else dp[0][1] = countWalls(walls, roboDist[0].first, roboDist[0].first + roboDist[0].second);
        for(int i=1; i<n; i++){
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + countWalls(walls, roboDist[i].first, min(roboDist[i].first + roboDist[i].second, roboDist[i+1].first-1));
            dp[i][0] = dp[i-1][0] + countWalls(walls, max(roboDist[i].first - roboDist[i].second, roboDist[i-1].first + 1), roboDist[i].first);
            int leftStart = max(roboDist[i].first - roboDist[i].second, roboDist[i-1].first + 1);
            int leftEnd = roboDist[i].first;
            int overlapStart = leftStart;
            int overlapEnd = min(roboDist[i].first-1, roboDist[i-1].first + roboDist[i-1].second);
            int currLeftButPrevRight = dp[i-1][1] + countWalls(walls, leftStart, leftEnd) - countWalls(walls, overlapStart, overlapEnd);
            dp[i][0] = max(currLeftButPrevRight, dp[i][0]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};
