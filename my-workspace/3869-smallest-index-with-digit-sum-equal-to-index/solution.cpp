class Solution {
public:
    int digitsum(int num){
        int sum = 0;
        while(num > 0){
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int sum = digitsum(num);
            if(i == sum){
                return i;
            }
        }
        return -1;
    }
};
