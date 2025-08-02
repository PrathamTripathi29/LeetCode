class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int currsum = 0;
        int count = 0;
        for(int i=0; i<n-1; i++){
            currsum += nums[i];
            if(currsum%2 == (sum-currsum)%2) count++;
        }
        return count;   
    }
};
