class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int l=0;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                maxLen = max(maxLen, i-l+1);
            } else {
                if(count == k){
                    while(count == k){
                        if(nums[l] == 0){
                            count--;
                        }
                        l++;
                    }
                }
                count++;
                maxLen = max(maxLen, i-l+1);
            }
        }
        return maxLen;
    }
};
