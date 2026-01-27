class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({w, v});
            adj[v].push_back({2*w, u});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(d > dist[node]) continue;
            for(auto &nbr : adj[node]){
                int nbrnode = nbr.second;
                int nbrdist = nbr.first;
                if(d + nbrdist < dist[nbrnode]){
                    dist[nbrnode] = d + nbrdist;
                    pq.push({dist[nbrnode], nbrnode});
                }
            }
        }
        if(dist[n-1] == INT_MAX){
            return -1;
        }
        return dist[n-1];
    }
};
