class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<vector<pair<int, int>>> adj(n);
    //     for(int i=0; i<flights.size(); i++){
    //         int u = flights[i][0];
    //         int v = flights[i][1];
    //         int d = flights[i][2];
    //         adj[u].push_back({v, d});
    //     }
    //     vector<int> dist(n, 1e8);
    //     dist[src] = 0;
    //     queue<tuple<int, int, int>> q;
    //     // tuple :- {stops, node, dist}
    //     q.push({0, src, 0});
    //     vector<pair<int, int>> ans;
    //     while(!q.empty()){
    //         auto [stops, node, d] = q.front();
    //         q.pop();
    //         if(stops > k) continue;
    //         for(auto nbr : adj[node]){
    //             int nbrnode = nbr.first;
    //             int nbrdist = nbr.second;
    //             if(nbrdist + d < dist[nbrnode] && stops <= k){
    //                 dist[nbrnode] = nbrdist + d;
    //                 q.push({stops + 1, nbrnode, dist[nbrnode]});
    //             }
                
    //         }
    //     }
    //     if(dist[dst] == 1e8) return -1;
    //     return dist[dst];
    // }
        vector<int> dist(n, 1e8);
        dist[src] = 0;
        for(int i=0; i<=k; i++){
            vector<int> temp = dist;
            for(auto& f : flights){
                int u = f[0];
                int v = f[1];
                int d = f[2];
                if(dist[u] != 1e8) temp[v] = min(temp[v], dist[u] + d);
            }
            dist = temp;
        }
        if(dist[dst] == 1e8) return -1;
        return dist[dst];
    }
};
