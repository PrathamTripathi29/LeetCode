class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int l = dimensions.size();
        int maxarea = 0;
        int maxdiag = 0;
        for(int i=0; i<l; i++){
            int currdiag = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            if(currdiag > maxdiag){
                maxarea = dimensions[i][0]*dimensions[i][1];
                maxdiag = currdiag;
            }
            if(currdiag == maxdiag){
                maxarea = max(maxarea, dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxarea;
    }
};
