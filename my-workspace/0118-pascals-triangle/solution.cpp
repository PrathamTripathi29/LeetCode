class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prevrow;
        for(int i=0; i < numRows; i++){
            vector<int> temp(i+1, 1);

            for(int j=1; j<i; j++){
                temp[j] = prevrow[j-1] + prevrow[j];
            }
            ans.push_back(temp);
            prevrow = temp;
        }
        return ans;
    }
};
