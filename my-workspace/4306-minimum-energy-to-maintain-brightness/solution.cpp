class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> mergedInterval;
        for(auto interval : intervals){
            if(mergedInterval.empty() || mergedInterval.back()[1] < interval[0]){
                mergedInterval.push_back(interval);
            } else {
                mergedInterval.back()[1] = max(mergedInterval.back()[1], interval[1]);
            }
        }
        long long ans = 0;
        int bulbsRequired = ceil((float)brightness/3);
        for(auto in : mergedInterval){
            long long len = in[1] - in[0] + 1;
            ans += (long long)len*bulbsRequired;
        }
        return ans;
    }
};
