class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = INT_MIN;
        int n = nums.size();
        vector<int> prefixGcd(n);
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int i=0;
        int j = n-1;
        while(i < j){
            int num1 = prefixGcd[i];
            int num2 = prefixGcd[j];
            sum += gcd(num1, num2);
            i++;
            j--;
        }
        return sum;
    }
};
