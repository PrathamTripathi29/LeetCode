class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ecost = 0;
        int ocost = 0;
        int size = position.size();
        for(int i=0; i<position.size(); i++){
            if(position[i]%2 != 0){
                ecost++;
            }
            else{
                ocost++;
            }
        }
        return min(ecost, ocost);
    }
};
