class Solution {
public:
    void dfs(int i, vector<vector<int>> &isConnected, vector<bool> &v){
        v[i] = true;
        for(int j=0; j<isConnected[i].size(); j++){
            if(isConnected[i][j] && v[j] == false){
                dfs(j, isConnected, v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> v(n, false);
        int count = 0;
        for(int i=0; i<n; i++){
            if(v[i] == false){
                count++;
                dfs(i, isConnected, v);
            }
        }
        return count; 
    }
};
