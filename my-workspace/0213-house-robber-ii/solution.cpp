class Solution {
public:
    int maxrob(vector<int> &nums, int start, int end){
        int rob1=0, rob2=0;
        for(int i=start; i<end; i++){
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }
        int max1 = maxrob(nums, 0, n-1);
        int max2 = maxrob(nums, 1, n);
        return max(max1, max2);
    }
};
