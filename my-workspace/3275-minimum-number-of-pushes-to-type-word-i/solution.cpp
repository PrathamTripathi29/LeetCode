class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        int l = word.length();
        if(l<=8){
            return l;
        }
        for(int i=0; i<l; i++){
            if(i<=7){
                pushes += 1;
            }
            if(i>7 && i<=15){
                pushes += 2;
            }
            if(i>15 && i<= 23){
                pushes += 3;
            }
            if(i>23) {
                pushes += 4;
            }       
        }
        return pushes;
    }
};
