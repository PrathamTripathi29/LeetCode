class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> knowsSecret(n, 0);
        knowsSecret[0] = 1;
        knowsSecret[firstPerson] = 1;
        map<int, vector<pair<int, int>>> mp;
        for(int i=0; i<meetings.size(); i++){
            mp[meetings[i][2]].push_back({meetings[i][0], meetings[i][1]});
        }
        for(auto it : mp){
            unordered_map<int, vector<int>> adj;
            unordered_set<int> vis;
            queue<int> q;
            for(int i=0; i<it.second.size(); i++){
                if(knowsSecret[it.second[i].first]){
                    q.push(it.second[i].first);
                }
                if(knowsSecret[it.second[i].second]){
                    q.push(it.second[i].second);
                }
                adj[it.second[i].first].push_back(it.second[i].second);
                adj[it.second[i].second].push_back(it.second[i].first);
            }
            while(!q.empty()){
                int node = q.front();
                q.pop();
                if(vis.count(node)){
                    continue;
                }
                vis.insert(node);
                for(int nbr : adj[node]){
                    knowsSecret[nbr] = 1;
                    if(!vis.count(nbr))
                        q.push(nbr);
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(knowsSecret[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
