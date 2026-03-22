class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int evenMin = INT_MAX;
        int oddMin = INT_MAX;
        int count = 0;
        for(int num : nums1){
            if(num&1){
                oddMin = min(oddMin, num);
                count++;
            } else {
                evenMin = min(evenMin, num);
            }
        }
        if(evenMin == INT_MAX || oddMin == INT_MAX) return true;
        if(evenMin > oddMin) return true;
        return false;
    }
};
