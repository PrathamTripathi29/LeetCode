class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l, r;
        int curvol = 0;
        int maxvol = 0;
        l=0;
        r = n-1;
        while(r>l){
            curvol = (r-l)*min(height[l], height[r]);
            if(curvol>maxvol){
                maxvol = curvol;
            }
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxvol;
    }
};
