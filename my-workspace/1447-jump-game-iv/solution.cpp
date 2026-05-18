class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        q.push({0, 0});
        while(!q.empty()){
            auto [idx, jumps] = q.front();
            q.pop();
            vector<int> indices = mp[arr[idx]];
            int idxl = idx-1;
            int idxr = idx+1;
            if(idxl >= 0 && jumps+1 < dist[idxl]){
                dist[idxl] = jumps+1;
                q.push({idxl, dist[idxl]});
            }
            if(idxr < n && jumps+1 < dist[idxr]){
                dist[idxr] = jumps+1;
                q.push({idxr, dist[idxr]});
            }
            for(int i=0; i<indices.size(); i++){
                if(indices[i] != idx){
                    if(jumps+1 < dist[indices[i]]){
                        dist[indices[i]] = jumps+1;
                        q.push({indices[i], jumps+1}); 
                    }
                }
            }
            mp[arr[idx]].clear();
        }
        return dist[n-1];
    }
};
