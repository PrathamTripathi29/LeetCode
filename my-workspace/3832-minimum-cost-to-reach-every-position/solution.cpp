class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        vector<int> ans;
        int currmin = cost[0];
        ans.push_back(currmin);
        for(int i=1; i<cost.size(); i++){
            if(currmin > cost[i]){
                currmin = cost[i];
            }
            ans.push_back(currmin);
        }
        return ans;
    }
};
