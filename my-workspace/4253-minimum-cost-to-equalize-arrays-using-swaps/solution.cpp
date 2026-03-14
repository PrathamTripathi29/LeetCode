class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int, int> mp1;
        map<int, int> mp2;
        int ans = 0;
        for(int i=0; i<n; i++){
            mp1[nums1[i]]++;
            mp2[nums2[i]]++;
        }
        set<int> nums;
        for(auto it : mp1){
            nums.insert(it.first);
        }
        for(auto it : mp2){
            nums.insert(it.first);
        }
        for(auto num : nums){
            int totalFreq =  mp1[num] + mp2[num];
            if(totalFreq%2) return -1;
            if(mp1[num] > totalFreq/2) ans += mp1[num] - totalFreq/2;
        }
        return ans;
    }
};
