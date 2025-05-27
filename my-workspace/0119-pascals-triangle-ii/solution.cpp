class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for(int i=0; i<=rowIndex; i++){
            vector<int> temp(i+1, 1);
            for(int j=1; j<i; j++){
                temp[j] = prev[j-1] + prev[j];
            }
            prev = temp;
        }
        return prev;
    }
};
