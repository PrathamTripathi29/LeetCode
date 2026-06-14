class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            unordered_map<int, int> freq;
            unordered_map<int, int> count;
            for(int j=i; j<n; j++){
                int prevFreq = 0;
                if(freq.find(nums[j]) != freq.end()){
                    prevFreq = freq[nums[j]];
                }
                freq[nums[j]]++;
                if(count.find(prevFreq) != count.end() && prevFreq != 0){
                    count[prevFreq]--;
                    if(count[prevFreq] == 0) count.erase(prevFreq);
                }
                count[freq[nums[j]]]++;
                if(freq.size() == 1 && count.size() == 1){
                    maxLen = max(maxLen, j-i+1);
                }
                else if(count.size() == 2){
                    auto it = count.begin();
                    int freq1 = it->first;
                    it++;
                    int freq2 = it->first;
                    int mx = max(freq1, freq2);
                    int mn = min(freq1, freq2);
                    if(mx == 2*mn) maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};
