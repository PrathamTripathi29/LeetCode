class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lr = 0;
        int hr = m-1;
        while(lr <= hr){
            int mr = lr + (hr - lr)/2;
            if(matrix[mr][0] == target) return true;
            if(matrix[mr][n-1] == target) return true;
            if(matrix[mr][0] < target && matrix[mr][n-1] > target){
                int l = 0;
                int h = n-1;
                while(l <= h){
                    int mid = l + (h-l)/2;
                    if(matrix[mr][mid] == target) return true;
                    if(matrix[mr][mid] > target){
                        h = mid-1;
                    } else {
                        l = mid + 1;
                    }
                }
                return false;
            }
            if(matrix[mr][0] < target){
                lr = mr + 1;
            } else {
                hr = mr - 1;
            }
        }
        return false;

    }
};
