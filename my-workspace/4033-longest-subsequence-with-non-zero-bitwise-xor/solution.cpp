class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        long long sum = 0;
        for(int num : nums){
            x = x^num;
            sum += num;
        }
        if(sum == 0) return 0;
        if(x == 0) return n-1;
        return n;
       
    }
};
