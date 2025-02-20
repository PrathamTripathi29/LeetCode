class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps(n+1);
        gaps[0] = startTime[0];
        gaps[n] = eventTime - endTime[n-1];

        for(int i=1; i<n; i++){
            gaps[i] = startTime[i] - endTime[i-1];
        }

        vector<int> prefixsum(n+2, 0);
        for(int i=1; i<n+2; i++){
            prefixsum[i] = prefixsum[i-1] + gaps[i-1];
        }

        int freetime = 0;
        for(int i=k+1; i< n+2; i++){
            freetime = max(freetime, prefixsum[i] - prefixsum[i-(k+1)]);
        }

        return freetime;

    }
};
