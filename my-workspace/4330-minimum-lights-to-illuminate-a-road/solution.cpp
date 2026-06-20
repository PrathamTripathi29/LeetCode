class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> illum(n+1, 0);
        for(int i=0; i<n; i++){
            if(lights[i] > 0){
                int l = max(0, i-lights[i]);
                int r = min(n-1, i+lights[i]);
                illum[l]++;
                illum[r+1]--;
            }
        }
        int count = 0;
        int isIllum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            isIllum += illum[i];
            if(isIllum <= 0){
                count++;
            } else {
                ans += ceil((double)count/3);
                count = 0;
            }
        }
        if(count > 0){
            ans += ceil((double)count/3);
        }
        return ans;
    }
};
