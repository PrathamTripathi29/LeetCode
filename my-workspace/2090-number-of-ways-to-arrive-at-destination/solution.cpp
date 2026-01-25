class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;
        vector<int> ways(n, 0);
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            int node = pq.top().second;
            long long t = pq.top().first;
            pq.pop();
            if(t > time[node]) continue;
            for(auto& nbr : adj[node]){
                int nbrnode = nbr[0];
                long long nbrt = nbr[1];
                if(nbrt + t == time[nbrnode]){
                    ways[nbrnode] = (ways[nbrnode] + ways[node]) % mod;
                }
                if(nbrt + t < time[nbrnode]){
                    pq.push({nbrt + t, nbrnode});
                    ways[nbrnode] = ways[node];
                    time[nbrnode] = nbrt + t;
                }
            }
        }
        return ways[n-1];
    }
};
