class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> prefixSum(n+1, 0);
        prefixSum[1] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i+1] = nums[i] + prefixSum[i];
        }
        int count = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                long long sum = prefixSum[j+1] - prefixSum[i];
                int ld = sum%10;
                while(sum >= 10){
                    sum /= 10;
                }
                int rd = sum;
                if(ld == x && rd == x) count++;
            }
        }
        return count;
    }
};
