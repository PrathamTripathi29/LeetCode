class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long sqsum = 0;
        long long idsum = n*(n+1)/2;
        long long sqidsum = n*(n+1)*(2*n+1)/6;
        for(int num : nums){
            sum += num;
            sqsum += (num*num);
        }
        long long d1 = idsum - sum;
        long long d2 = (sqidsum - sqsum)/d1;
        int m = (d1 + d2)/2;;
        int d = (d2-d1)/2;
        return {d, m};
    }
};
