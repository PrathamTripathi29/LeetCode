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
    int removeStones(vector<vector<int>>& stones) {
            int n = stones.size();
            int maxRow = 0;
            int maxCol = 0;
            for(auto stone : stones){
                maxRow = max(maxRow, stone[0]);
                maxCol = max(maxCol, stone[1]);
            }
            DisjointSet djs(maxRow + maxCol + 1);
            unordered_map<int, int> stoneNodes;
            for(auto stone : stones){
                int row = stone[0];
                int col = stone[1] + maxRow  + 1;
                djs.unionBySize(row, col);
                stoneNodes[row] = 1;
                stoneNodes[col] = 1;
            }
            int count = 0;
            for(auto it : stoneNodes){
                if(djs.findUPar(it.first) == it.first){
                    count++;
                }
            }
            return n-count;
    }
};
