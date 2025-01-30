class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int Gas = 0, tank = 0, Cost = 0, start = 0;;
        int n = gas.size();
        for(int i=0; i<n; i++){
            Gas = Gas + gas[i];
            Cost = Cost + cost[i];
            tank = tank + gas[i] - cost[i];
            if(tank<0){
                start = i + 1;
                tank = 0;
            }
        }
        if(Gas>=Cost){
            return start;
        }
        else{
            return -1;
        }
    }
};
