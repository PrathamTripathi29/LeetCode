class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> ans;
        int top, left, right, bottom;
        top = left = 0;
        bottom = rows-1;
        right = cols-1;

        while(top <= bottom && left <= right){
            if(top <= bottom && left <= right){
                for(int j = left; j<=right; j++){
                    ans.push_back(matrix[top][j]);
                }
            }
            top++;
            if(top<=bottom && left<=right){
                for(int i=top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
            }
            right--;
            if(top<=bottom && left<=right){
                for(int j=right; j>=left; j--){
                    ans.push_back(matrix[bottom][j]);
                }
            }
            bottom--;
            if(top <= bottom && left <= right){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return ans;
    }
};
