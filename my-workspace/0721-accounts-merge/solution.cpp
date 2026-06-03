class DisjointSet {
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv) return;
        if(rank[upu] < rank[upv]){
            parent[upu] = upv;
        } else if(rank[upv] < rank[upu]){
            parent[upv] = upu;
        } else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }

    void unionBySize(int u, int v){
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv) return;
        if(size[upu] < size[upv]){
            parent[upu] = upv;
            size[upv] += size[upu];
        } else {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet djs(n);
        unordered_map<string, int> mp;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                } else {
                    djs.unionByRank(i, mp[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto& it : mp){
            string mail = it.first;
            int node = djs.findUPar(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++){
            if(merged[i].empty()) continue;
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            sort(merged[i].begin(), merged[i].end());
            temp.insert(temp.end(), merged[i].begin(), merged[i].end());
            ans.push_back(temp);
        }
        return ans;
    }
};
