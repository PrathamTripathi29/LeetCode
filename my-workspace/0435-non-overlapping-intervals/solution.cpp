class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prev = INT_MIN;
        for(int i=0; i<n; i++){
            int st = intervals[i][0];
            int ed = intervals[i][1];
            if(st < prev){
                count++;
                prev = min(prev, ed);
            } else {
                prev = ed;
            }
        }
        return count;
    }
};
