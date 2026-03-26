class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int nbr : adj[node]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0) q.push(nbr);
            }
        }
        if(ans.size() == numCourses) return true;
        return false;
        
    }
};
