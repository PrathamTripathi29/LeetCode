class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> colored(n, -1);
        for(int i=0; i<n; i++){
            if(colored[i] != -1){
                continue;
            }
            colored[i] = 0;
            q.push(i);

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int adjnode : graph[node]){
                    if(colored[adjnode] == -1){
                        colored[adjnode] = !colored[node];
                        q.push(adjnode);
                    } else if(colored[adjnode] == colored[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
