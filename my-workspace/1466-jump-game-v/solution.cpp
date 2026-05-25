class Solution {
public:
    int f(int i, vector<int>& arr, vector<int>& dp, int n, int d){
        if(dp[i] != -1) return dp[i];
        int mx=1;
        for(int j=1; j<=d && i+j < n; j++){
            if(arr[i] > arr[i+j]){
                mx = max(mx, 1+f(i+j, arr, dp, n, d));
            } else break;
        }
        for(int j=1; j<=d && i-j>=0; j++){
            if(arr[i] > arr[i-j]){
                mx = max(mx, 1+f(i-j, arr, dp, n, d));
            } else break;
        }
        return dp[i] = mx;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, f(i, arr, dp, n, d));
        }
        return ans;
    }
};
