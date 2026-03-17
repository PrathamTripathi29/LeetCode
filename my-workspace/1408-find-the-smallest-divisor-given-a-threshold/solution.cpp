class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = INT_MIN;
        for(auto num : nums){
            mx = max(mx, num);
        }
        int low = 1;
        int high = mx+1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int sum = 0;
            for(int num : nums){
                int quo = ceil((double)num/mid);
                sum += quo;
            }
            if(sum <= threshold){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
