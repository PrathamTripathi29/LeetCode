class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int len = 0;
        for(int num : s){
            if(s.find(num-1) == s.end()){
                int l = 1;
                while(s.find(num+l) != s.end()){
                    l++;
                }
                len = max(len, l);
            }
        }
        return len;
    }
};
