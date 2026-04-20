class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int lmax=0, rmax=0;
        int cf = colors[0];
        int cl = colors[n-1];
        for(int i=0; i<n; i++){
            if(cf != colors[i]) lmax = max(lmax, i);
            if(cl != colors[i]) rmax = max(rmax, n-1-i);
        }
        return max(lmax, rmax);
    }
};
