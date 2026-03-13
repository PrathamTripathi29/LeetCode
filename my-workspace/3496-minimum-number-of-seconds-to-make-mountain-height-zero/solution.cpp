class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n = workerTimes.size();
        int mini = INT_MAX;
        for(int w : workerTimes) mini = min(mini, w);
        long long low = 1;
        long long high = (long long)mini * mountainHeight * (mountainHeight+1)/2;
        while(low <= high){
            long long mid = low + (high - low)/2;
            long long totalHeightReduced = 0;
            for(int i=0; i<n; i++){
                long long heightReduced = 0;
                heightReduced = floor((sqrt((double)8*mid/workerTimes[i] + 1) - 1)/2);
                totalHeightReduced += heightReduced;
            }
            if(totalHeightReduced >= mountainHeight){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return low;
    }
};
