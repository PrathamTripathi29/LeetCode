class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();
        int i=0, j=0;
        int num=0;
        while(num < m*n){
            ans.push_back(mat[i][j]);
            if((i+j) % 2 == 0){
                if(j == n-1){
                    i++;
                } else if(i == 0){
                    j++;
                } else{
                    i--;
                    j++;
                }
            } else {
                if(i == m-1){
                    j++;
                } else if(j == 0){
                    i++;
                } else{
                    i++;
                    j--;
                }
            }
            num++;
        }
        return ans;
    }
};
