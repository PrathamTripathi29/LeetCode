class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int j=0; j<n; j++){
            unordered_set<int> even;
            unordered_set<int> odd;
            for(int i=j; i<n; i++){
                if(nums[i]%2 == 0){
                    even.insert(nums[i]);
                } else{
                    odd.insert(nums[i]);
                }
                if(even.size() == odd.size()){
                    maxLen = max(maxLen, i-j+1);
                }
            }
        } 
        return maxLen; 
    }
};
