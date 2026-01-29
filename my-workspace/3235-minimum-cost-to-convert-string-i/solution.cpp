class Solution {
public:
    void findCost(int node, vector<vector<pair<int, int>>>& adj, vector<int>& dist){
        dist[node] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, node});
        while(!pq.empty()){
            auto [d, n] = pq.top();
            pq.pop();
            for(auto [nd, nb] : adj[n]){
                if(d > dist[nb]){
                    continue;
                }
                if(nd + d < dist[nb]){
                    pq.push({nd + d, nb});
                    dist[nb] = d + nd;
                }
            }
        }

    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int, int>>> adj(26);
        for(int i=0; i<original.size(); i++){
            adj[original[i] - 'a'].push_back({cost[i], changed[i] - 'a'});
        }
        vector<vector<int>> dist(26, vector<int>(26, INT_MAX));
        for(int i=0; i<26; i++){
            findCost(i, adj, dist[i]);
        }
        long long ans = 0;
        for(int i=0; i<source.size(); i++){
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(u == v) continue;
            if(dist[u][v] == INT_MAX) return -1;
            ans += dist[u][v];
        }
        return ans;
    }
};
