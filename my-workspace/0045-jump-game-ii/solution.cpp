class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        int jumps = 0;
        int currIdx = 0;
        while(maxReach < n-1){
            int currMax = 0;
            for(int i=currIdx; i<=maxReach; i++){
                currMax = max(currMax, i + nums[i]);
            }
           currIdx = maxReach+1;
           maxReach = max(maxReach, currMax);
           jumps++;
        }
        return jumps;
    }
};
