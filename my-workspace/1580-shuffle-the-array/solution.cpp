class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        int idx = 0;
        int e=0;
        int o=0;
        while(idx < 2*n){
            if(idx&1){
                ans[idx] = nums[n+o];
                o++;
            } else {
                ans[idx] = nums[e];
                e++;
            }
            idx++;
        }
        return ans;
    }
};
