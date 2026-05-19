class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for(auto road : roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        // dist, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            for(auto nbr : adj[node]){
                if(d + nbr.second < dist[nbr.first]){
                    dist[nbr.first] = d + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                    ways[nbr.first] = ways[node];
                } else if(d + nbr.second == dist[nbr.first]){
                    ways[nbr.first] = (ways[nbr.first] + ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};
