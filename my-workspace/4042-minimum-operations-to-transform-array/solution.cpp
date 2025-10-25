class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long ops = 0;
        int mindiff = INT_MAX;
        int val = nums2[n];
        bool append = false;
        for(int i=0; i<n; i++){
            if(val >= min(nums1[i], nums2[i]) && val <= max(nums1[i], nums2[i])){
                append = true;
            }
            int currdiff = abs(nums1[i] - nums2[n]);
            mindiff = min(mindiff, currdiff);
            ops += abs(nums2[i] - nums1[i]);
            currdiff = abs(nums2[i] - nums2[n]);
            mindiff = min(mindiff, currdiff);
        }
        if(append){
            ops++;
        } else {
            ops += mindiff;
            ops++;
        }
        return ops;
    }
};
