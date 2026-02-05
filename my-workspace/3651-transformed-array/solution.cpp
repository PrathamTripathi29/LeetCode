class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            int num = nums[i];
            int val;
            if(num > 0){
                val = nums[(i+num)%n];
            } else if(num < 0){
                int Newnum = n - abs(num%n);
                val = nums[(i+Newnum)%n];
            } else{
                val = num;
            }
            result[i] = val;
        }
        return result;
    }
};
