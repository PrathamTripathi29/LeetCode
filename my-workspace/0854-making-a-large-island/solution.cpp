class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v){
        int upu = findUPar(u);
        int upv = findUPar(v);
        if(upu == upv) return;
        if(size[upu] >= size[upv]){
            parent[upv] = upu;
            size[upu] += size[upv]; 
        } else {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet djs(n*n);
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 1){
                    for(int i=0; i<4; i++){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            djs.unionBySize(r*n + c, nr*n + nc);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c] == 0){
                    set<int> comps;
                    for(int i=0; i<4; i++){
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                        if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 1){
                            int up = djs.findUPar(nr*n+nc);
                            comps.insert(up);
                        }
                    }
                    int size = 1;
                    for(auto it : comps){
                        size += djs.size[it];
                    }
                    ans = max(ans, size);
                }
            }
        }
        for(int i=0; i<n*n; i++){
            ans = max(ans, djs.size[i]);
        }
        return ans;
    }
};
