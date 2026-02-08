class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n, 0);
        if(n == 1) return 0;
        for(int i=n-2; i>=0; i--){
            suffix[i] = suffix[i+1] + nums[i+1];
        }
        int count = 0;
        for(int i=0; i<n; i++){
            float avg = (float)suffix[i]/(n-i-1);
            if((float)nums[i] > avg){
                count++;
            }
        }
        return count;
    }
};
