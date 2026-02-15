class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freqNums;
        for(int i=0; i<nums.size(); i++){
            freqNums[nums[i]]++;
        }
        unordered_map<int, int> freqFreq;
        for(auto& it : freqNums){
            freqFreq[it.second]++;
        }
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            int freq = freqNums[nums[i]];
            int freqF = freqFreq[freq];
            if(freqF == 1){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};
