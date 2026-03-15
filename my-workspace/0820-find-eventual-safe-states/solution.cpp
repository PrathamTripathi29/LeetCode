class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& isSafeNode){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int nbr : graph[node]){
            if(!vis[nbr]){
                if(dfs(nbr, graph, vis, pathVis, isSafeNode)) return true;
            } else if(pathVis[nbr]){
                return true;
            }
        }
        pathVis[node] = 0;
        isSafeNode[node] = 1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> isSafeNode(n, 0);
        vector<int> safeNodes;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, graph, vis, pathVis, isSafeNode);
            }
        }
        for(int i=0; i<n; i++){
            if(isSafeNode[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
