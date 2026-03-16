class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 2);
        vector<int> right(n, 2);
        int ans = 2;
        left[0] = 1;
        right[n-1] = 1;
        for(int i=2; i<n; i++){
            int d1 = nums[i] - nums[i-1];
            int d2 = nums[i-1] - nums[i-2];
            if(d1 == d2){
                left[i] = left[i-1] + 1;
            }
        }
        for(int i=n-3; i>=0; i--){
            int d1 = nums[i+1] - nums[i];
            int d2 = nums[i+2] - nums[i+1];
            if(d1 == d2){
                right[i] = right[i+1] + 1;
            }
        }
        for(int i=0; i<n; i++){
            if(i > 0) ans = max(ans, left[i-1] + 1);
            if(i < n-1) ans = max(ans, right[i+1] + 1);
            if(i > 0 && i < n-1){
                int d = nums[i+1] - nums[i-1];
                if(d%2 == 0){
                    int reqd = d/2;
                    int leftLen = 1;
                    if(i >= 2 && nums[i-1] - nums[i-2] == reqd){
                        leftLen = left[i-1];
                    }
                    int rightLen = 1;
                    if(i < n-2 && nums[i+2] - nums[i+1] == reqd){
                        rightLen = right[i+1];
                    }
                    ans = max(ans, leftLen+rightLen+1);
                }
            }
        }
        return ans;
    }
};
