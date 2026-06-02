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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet djs(n);
        int extra = 0;
        int components = 0;
        for(auto connection : connections){
            int a = connection[0];
            int b = connection[1];
            if(djs.findUPar(a) == djs.findUPar(b)){
                extra++;
            } else {
                djs.unionByRank(a, b);
            }
        }
        for(int i=0; i<n; i++){
            if(djs.parent[i] == i) components++;
        }
        if(extra >= components-1) return components-1;
        return -1;
    }
};
