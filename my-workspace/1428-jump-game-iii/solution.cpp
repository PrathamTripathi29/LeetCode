class Solution {
public:
    bool dfs(int start, vector<int>& arr, vector<int>& vis, int n){
        if(start < 0 || start >= n || vis[start]) return false;
        if(arr[start] == 0) return true;
        vis[start] = 1;
        int left = start - arr[start];
        int right = start + arr[start];
        return dfs(left, arr, vis, n) || dfs(right, arr, vis, n);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);
        return dfs(start, arr, vis, n);
    }
};
