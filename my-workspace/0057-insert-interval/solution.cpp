class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start = newInterval[0];
        int end = newInterval[1];
        int i;
        for(i=0; i<intervals.size(); i++){
            if(intervals[i][0] > end){
                break;
            }
            if(intervals[i][1] < start){
                ans.push_back(intervals[i]);
            }
            else{
                start = min(start, intervals[i][0]);
                end = max(end, intervals[i][1]);
            }
        }
        ans.push_back({start, end});
        for(; i<intervals.size(); i++){
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};
