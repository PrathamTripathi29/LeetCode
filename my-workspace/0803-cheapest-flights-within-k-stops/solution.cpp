class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight : flights){
            int u = flight[0];
            int v = flight[1];
            int d = flight[2];
            adj[u].push_back({v, d});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // dist, city, stops
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});
        while(!q.empty()){
            auto [d, c, s] = q.front();
            q.pop();
            if(s > k) continue;
            for(auto nbr : adj[c]){
                if(d + nbr.second < dist[nbr.first] && s <= k){
                    q.push({d + nbr.second, nbr.first, s+1});
                    dist[nbr.first] = d + nbr.second;
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};
