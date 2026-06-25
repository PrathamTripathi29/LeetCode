class Solution {
public:
    void expand(int& o, int num, vector<int>& bitCount){
        for(int i=0; i<32; i++){
            if(num&(1<<i)){
                bitCount[i]++;
                o = o | (1<<i);
            }
        }
    }
    void compress(int& o, int num, vector<int>& bitCount){
        for(int i=0; i<32; i++){
            if(num&(1<<i)){
                bitCount[i]--;
                if(bitCount[i] == 0){
                    o = o & (~(1<<i));
                }
            }
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int o = 0;
        int n = nums.size();
        int l=0;
        int minLen = INT_MAX;
        vector<int> bitCount(32, 0);
        for(int i=0; i<n; i++){
            expand(o, nums[i], bitCount);
            while(o >= k && l <= i){
                minLen = min(minLen, i-l+1);
                compress(o, nums[l], bitCount);
                l++;
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};
