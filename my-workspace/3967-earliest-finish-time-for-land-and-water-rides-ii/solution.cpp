class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landDuration.size();
        int m = waterDuration.size();
        int minLandEnd = INT_MAX;
        int minWaterEnd = INT_MAX;
        for(int i=0; i<n; i++){
            int landEnd = landStartTime[i] + landDuration[i];
            minLandEnd = min(minLandEnd, landEnd);
        }
        for(int i=0; i<m; i++){
            int waterEnd = waterStartTime[i] + waterDuration[i];
            minWaterEnd = min(minWaterEnd, waterEnd);
        }
        int ans1 = INT_MAX;
        int ans2 = INT_MAX;
        for(int i=0; i<m; i++){
            ans1 = min(ans1, max(minLandEnd, waterStartTime[i]) + waterDuration[i]);
        }
        for(int i=0; i<n; i++){
            ans2 = min(ans2, max(minWaterEnd, landStartTime[i]) + landDuration[i]);
        }
        return min(ans1, ans2);
    }
};
