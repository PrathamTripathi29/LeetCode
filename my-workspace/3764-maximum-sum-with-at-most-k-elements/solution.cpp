class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long maxsum = 0;
        int m = grid[0].size();
        int n = grid.size();
        int numsused = 0;
        for(int i=0; i<n; i++){
            sort(grid[i].rbegin(), grid[i].rend());
        }
        vector<int> sum;
        for(int i=0; i<n; i++){
            int j=0;
            while(limits[i] > 0){
                sum.push_back(grid[i][j]);
                j++;
                limits[i]--;
            }
        }      
        sort(sum.rbegin(), sum.rend());
        int index=0;
        while(numsused < k){
            maxsum += sum[index];
            index++;
            numsused++;
        }
        return maxsum;
    }
};
