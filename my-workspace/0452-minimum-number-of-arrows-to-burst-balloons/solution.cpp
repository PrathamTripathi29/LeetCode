class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> common;
        vector<int> temp = points[0];
        for(int i=1; i<points.size(); i++){
            if(temp[1] >= points[i][0]){
                temp[0] = max(temp[0], points[i][0]);
                temp[1] = min(temp[1], points[i][1]);
            }
            else{
                common.push_back(temp);
                temp = points[i];
            }
        }
        common.push_back(temp);
        return common.size();
    }
};
