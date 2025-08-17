class Solution {
public:
    int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        for(int i=0; i<q; i++){
            int idx = queries[i][0];
            while(idx <= queries[i][1]){
                nums[idx] = ((long long)nums[idx] * queries[i][3] % mod);
                idx += queries[i][2];
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};
