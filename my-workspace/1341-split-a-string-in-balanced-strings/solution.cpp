class Solution {
public:
    int balancedStringSplit(string s) {
        int diff = 0;
        int k = 0;
        for(int i=0; i<s.length(); i++){
            if(s.at(i) == 'R'){
                diff++;
            }
            else{
                diff--;
            }
            if(diff == 0){
                k++;
            }
        }
        return k;
    }
};
