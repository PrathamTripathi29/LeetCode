class Solution {
public:
    bool check(int mid, vector<int>& nums, int th){
        long long res = 0;
        for(int num : nums){
            res += ceil((double)num/mid);
        }
        return res <= th;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(mid, nums, threshold)){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
