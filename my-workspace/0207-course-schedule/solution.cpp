class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int nbr : adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr, adj, vis, pathVis) == false){
                    return false;
                }
            }else if(pathVis[nbr]){
                return false;
            }
        }
        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
