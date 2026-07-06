class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> covered;
        for(auto& in : intervals){
            if(covered.empty()){
                covered.push_back(in);
                continue;
            }
            int st = covered.back()[0];
            int ed = covered.back()[1];
            if(ed < in[1]){
                if(st < in[0])
                    covered.push_back(in);
                else {
                    covered.pop_back();
                    covered.push_back(in);
                }
            }
        }
        return covered.size();
    }
};
