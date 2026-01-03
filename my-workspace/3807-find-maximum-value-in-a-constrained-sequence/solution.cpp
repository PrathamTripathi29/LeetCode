class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<int> arr(n, INT_MAX);
        arr[0] = 0;
        for(auto it : restrictions){
            int idx = it[0];
            int maxVal = it[1];
            arr[idx] = min(arr[idx], maxVal);
        }
        for(int i = 1; i<n; i++){
            arr[i] = min(arr[i], arr[i-1] + diff[i-1]);
        }
        for(int i = n-2; i>=0; i--){
            arr[i] = min(arr[i], arr[i+1] + diff[i]);
        }
        int ans = INT_MIN;
        for(int num : arr){
            ans = max(ans, num);
        }
        return ans;
    }
};
