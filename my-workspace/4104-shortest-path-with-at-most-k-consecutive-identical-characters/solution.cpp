class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        // dist, node, consec
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k+1, LLONG_MAX)); 
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        while(!pq.empty()){
            auto [d, node, consec] = pq.top();
            pq.pop();
            if(d > dist[node][consec]) continue;
            for(auto nbr : adj[node]){
                int nbrnode = nbr.first;
                int w = nbr.second;
                char label = labels[nbrnode];
                if(label == labels[node] && consec < k){
                    
                    if(d+w < dist[nbrnode][consec]){ dist[nbrnode][consec] = d+w;
                    pq.push({d+w, nbrnode, consec+1});}
                } else if(label != labels[node]){
                     if(d+w < dist[nbrnode][consec]){ dist[nbrnode][consec] = d+w;
                     pq.push({d+w, nbrnode, 1});}
                }
            }
        }
        int ans = *min_element(dist[n-1].begin(), dist[n-1].end());
        return ans == INT_MAX ? -1 : ans;
    }
};
