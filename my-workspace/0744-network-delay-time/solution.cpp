class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e8);
        dist[k] = 0;
        for(int i=0; i<n; i++){
            for(auto t : times){
                int u = t[0];
                int v = t[1];
                int d = t[2];
                if(dist[u] != 1e8 && dist[u] + d < dist[v]){
                    dist[v] = dist[u] + d;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=n; i++){
            if(dist[i] == 1e8) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
