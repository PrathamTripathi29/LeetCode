class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> dp;
        for(int i=0; i<numRows; i++){
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++){
                temp[j] = dp[j-1] + dp[j];
            }
            ans.push_back(temp);
            dp = temp;
        }
        return ans;
    }
};
