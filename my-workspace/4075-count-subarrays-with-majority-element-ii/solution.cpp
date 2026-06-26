class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target) nums[i] = 1;
            else nums[i] = -1;
        }
        vector<int> pref(n);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }
        int offset = n;
        vector<int> freq(2*n + 1, 0);

        freq[offset] = 1;

        long long valid = 0;
        int lastSum = 0;
        long long count = 0;
        for(int i=0; i<n; i++){
            if(pref[i] > lastSum){
                valid += freq[lastSum+offset];
            } else {
                valid -= freq[pref[i]+offset];
            }
            count += valid;
            freq[pref[i]+offset]++;
            lastSum = pref[i];
        }
        return count;
    }
};
