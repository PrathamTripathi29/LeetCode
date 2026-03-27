class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        // vector<vector<int>> newMat = mat;
        // for(int rot=0; rot<(k%n); rot++){
        //     for(int i=0; i<m; i++){
        //         if(i%2){
        //             int last = newMat[i][n-1];
        //             for(int j=n-1; j>=1; j--){
        //                 newMat[i][j] = newMat[i][j-1];
        //             }
        //             newMat[i][0] = last;
        //         } else {
        //             int first = newMat[i][0];
        //             for(int j=0; j<n-1; j++){
        //                 newMat[i][j] = newMat[i][j+1];
        //             }
        //             newMat[i][n-1] = first;
        //         }
        //     }
        // }
        // if(newMat == mat) return true;
        // return false;
        k = k%n;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int idx;
                if(i%2){
                    idx = (j+k)%n;
                } else {
                    idx = (j-k+n)%n;
                }
                if(mat[i][j] != mat[i][idx]) return false;
            }
        }
        return true;
    }
};
