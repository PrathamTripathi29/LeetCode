class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> merged;
        vector<vector<int>> ans;
        for(auto in : occupiedIntervals){
            if(merged.empty()){
                merged.push_back(in);
                continue;
            }
            if(in[0] <= merged.back()[1] + 1){
                merged.back()[1] = max(merged.back()[1], in[1]);
            } else {
                merged.push_back(in);
            }
        }
        for(auto in : merged){
            int st = in[0];
            int ed = in[1];
            if(ed < freeStart || st > freeEnd){
                ans.push_back(in);
            } else if(st < freeStart && ed > freeEnd){
                ans.push_back({st, freeStart-1});
                ans.push_back({freeEnd+1, ed});
            } else if(st < freeStart){
                ans.push_back({st, freeStart-1});
            } else if(ed > freeEnd){
                ans.push_back({freeEnd+1, ed});
            }
        }
        return ans;
    }
};
