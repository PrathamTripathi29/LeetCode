class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        int i=0, j=0;
        int ans = 0;
        while(i < n1 && j < n2){
            if(i<=j && nums1[i] <= nums2[j]){
                ans = max(ans, j-i);
                j++;
            } else if(i <= j){
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};
