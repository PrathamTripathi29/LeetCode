class Solution {
public:
    long long dfs(int node, vector<int>& baseTime, vector<vector<int>>& adj, vector<long long>& dp){
        if(adj[node].empty()){
            return baseTime[node];
        }
        if(dp[node] != -1) return dp[node];
        long long mn = LLONG_MAX;
        long long mx = LLONG_MIN;
        for(auto child : adj[node]){
            long long time = dfs(child, baseTime, adj, dp);
            mn = min(mn, time);
            mx = max(mx, time);
        }
        return dp[node] = (2*mx)-mn+baseTime[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        vector<long long> dp(n, -1);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        return dfs(0, baseTime, adj, dp);
    }
};
