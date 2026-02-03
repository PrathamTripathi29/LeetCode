class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int via = 0; via < n; via++){
            for(int src = 0; src < n; src++){
                for(int dest = 0; dest < n; dest++){
                    if(dist[src][via] == INT_MAX || dist[via][dest] == INT_MAX) continue;
                    dist[src][dest] = min(dist[src][dest], dist[src][via] + dist[via][dest]);
                }
            }
        }
        vector<int> numberOfCities(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(dist[i][j] <= distanceThreshold){
                    numberOfCities[i]++;
                }
            }
        }
        int minCities = INT_MAX;
        for(int i=0; i<n; i++){
            minCities = min(minCities, numberOfCities[i]);
        }
        for(int i=n-1; i>=0; i--){
            if(numberOfCities[i] == minCities){
                return i;
            }
        }
        return 0;
    }
};
