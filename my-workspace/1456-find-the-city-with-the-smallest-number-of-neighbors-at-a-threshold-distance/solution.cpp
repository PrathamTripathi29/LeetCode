class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dist[i][i] = 0;
        }
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            dist[u][v] = d;
            dist[v][u] = d;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int city = -1;
        int minCount = n;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= minCount){
                minCount = count;
                city = i;
            }
        }
        return city;
    }
};
