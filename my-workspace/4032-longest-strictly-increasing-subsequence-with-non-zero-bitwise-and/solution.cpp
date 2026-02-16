class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<32; i++){
            vector<int> vec;
            vector<int> sub;
            for(int num : nums){
                if(num & 1<<i){
                    vec.push_back(num);
                }
            }
            for(int num : vec){
                if(sub.empty() || sub.back() < num){
                    sub.push_back(num);
                    continue;
                }
                auto it = lower_bound(sub.begin(), sub.end(), num);
                *it = num; 
            }
            int len = sub.size();
            ans = max(ans, len);
        }
        return ans;
    }
};
