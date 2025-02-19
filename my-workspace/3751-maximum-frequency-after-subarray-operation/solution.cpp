class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int kcount = count(nums.begin(), nums.end(), k);
        int maximum = 0;
        for (int m = 1; m <= 50; ++m) {
            if (m == k) continue;
            int cur = 0, maxcur = 0;
            for (int n : nums) {
                cur += n == m ? 1 : n == k ? -1 : 0;
                cur = max(cur, 0);
                maxcur = max(maxcur, cur);
            }
            maximum = max(maximum, maxcur);
        }
        return kcount + maximum;
    }
};
