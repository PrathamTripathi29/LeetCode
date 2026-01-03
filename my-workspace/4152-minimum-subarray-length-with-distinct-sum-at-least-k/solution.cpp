class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int currlen = INT_MAX;
        int currsum = 0;
        unordered_map<int, int> freq;
        int l, r;
        int n = nums.size();
        l = r = 0;
        while(r < n){
            if(freq[nums[r]] == 0){
                currsum += nums[r];
            }
            freq[nums[r]]++;
            while(currsum >= k){
                currlen = min(currlen, r - l + 1);
                freq[nums[l]]--;
                if(freq[nums[l]] == 0){
                    currsum -= nums[l];
                }
                l++;
            }
            r++;
        }
        if(currlen == INT_MAX) return -1;
        return currlen;
    }
};
