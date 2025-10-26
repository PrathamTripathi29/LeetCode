class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long neg = 0;
        long long pos = 0;
        int n = nums.size();
        int negsize = n/2;
        int possize = n - negsize;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        int i = 0;
        while(i<negsize){
            neg += nums[i]*nums[i];
            i++;
        }
        while(i<n){
            pos += nums[i]*nums[i];
            i++;
        }
        return pos - neg;
    }
};
