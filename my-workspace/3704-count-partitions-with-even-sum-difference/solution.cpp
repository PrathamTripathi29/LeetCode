class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }
        int currSum = 0;
        int ans = 0;
        for(int num : nums){
            currSum += num;
            if(abs(sum - 2*currSum)%2 == 0 && currSum != sum) ans++;
        }
        return ans;
    }
};
