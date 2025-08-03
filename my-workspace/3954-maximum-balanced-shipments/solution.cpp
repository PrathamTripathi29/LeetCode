class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int shipments = 0;
        int n = weight.size();
        int left = 0;
        int currmax = weight[0];
        for(int i=1; i<n; i++){
            if(weight[i] < currmax){
                shipments++;
                left = i+1;
                currmax = weight[left];
            } else{
                currmax = weight[i];
            }
        }
        return shipments;
    }
};
