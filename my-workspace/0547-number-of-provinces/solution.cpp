class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& vis, int n){
        vis[city] = 1;
        for(int i=0; i<n; i++){
            if(isConnected[city][i] && !vis[i]){
                dfs(i, isConnected, vis, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, isConnected, vis, n);
            }
        }
        return provinces;
    }
};
