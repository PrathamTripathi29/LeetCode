class Solution {
public:
    int getLeastFrequentDigit(int n) {
        unordered_map<int, int> mp;
        int orinum = n;
        while(n > 0){
            int digit = n%10;
            if(mp.count(digit)){
                mp[digit]++;
            } else{
                mp[digit] = 1;
            }
            n = n/10;
        }
        int mini = INT_MAX;
        int ans = INT_MAX;
        for(const auto &pair : mp){
            if(pair.second < mini){
                mini = pair.second;
                ans = pair.first;
            } else if(pair.second == mini){
                ans = min(ans, pair.first);
            }
        }
        return ans;
    }
};
