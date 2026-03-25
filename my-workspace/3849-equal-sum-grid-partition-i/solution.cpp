class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> rowSum(m, 0);
        vector<long long> colSum(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
            }
        }
        vector<long long> suffixRowSum(m, 0);
        suffixRowSum[0] = rowSum[0];
        for(int i=1; i<m; i++){
            suffixRowSum[i] = rowSum[i] + suffixRowSum[i-1];
        }
        vector<long long> suffixColSum(n, 0);
        suffixColSum[0] = colSum[0];
        for(int i=1; i<n; i++){
            suffixColSum[i] = colSum[i] + suffixColSum[i-1];
        }
        for(int i=0; i<m; i++){
            long long topSum = suffixRowSum[i];
            long long downSum = suffixRowSum[m-1] - topSum;
            if(topSum == downSum) return true;
        }
        for(int i=0; i<n; i++){
            long long leftSum = suffixColSum[i];
            long long rightSum = suffixColSum[n-1] - leftSum;
            if(leftSum == rightSum) return true;
        }
        return false;
    }
};
