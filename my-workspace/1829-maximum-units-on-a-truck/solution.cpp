class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int size = boxTypes.size();
        int totalboxesputon = 0;
        int boxesputon = 0;
        int units = 0;
        for(int i = 0; i<size-1; i++){
            for(int j = i + 1; j<size; j++){
                if(boxTypes[i][1] < boxTypes[j][1]){
                    int temp0, temp1;
                    temp0 = boxTypes[i][0];
                    temp1 = boxTypes[i][1];
                    boxTypes[i][0] = boxTypes[j][0];
                    boxTypes[i][1] = boxTypes[j][1];
                    boxTypes[j][0] = temp0;
                    boxTypes[j][1] = temp1;
                }
            }
        }
        int i = 0;
        while(totalboxesputon < truckSize && i<size){
            if(truckSize - totalboxesputon >= boxTypes[i][0]){
                boxesputon = boxTypes[i][0];
            }
            else{
                boxesputon = truckSize - totalboxesputon;
            }
            totalboxesputon += boxesputon;
            units += boxesputon*boxTypes[i][1];
            boxesputon = 0;
            i++;
        }
        return units;
    }
};
