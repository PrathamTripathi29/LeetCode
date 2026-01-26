class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int m = INT_MAX;
        for(int i=1; i<arr.size(); i++){
            m = min(m, abs(arr[i] - arr[i-1]));
        }
        for(int i=1; i<arr.size(); i++){
            if(abs(arr[i] - arr[i-1]) == m){
                ans.push_back({arr[i-1], arr[i]});
            }
        }
        return ans;
    }
};
