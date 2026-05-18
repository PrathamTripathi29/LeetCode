class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ops = 0;
        while(target > 1){
            if(target&1 && maxDoubles > 0){
                target--;
                ops++;
            }
            else if(maxDoubles > 0){
                target /= 2;
                ops++;
                maxDoubles--;
            } else {
                ops += (target-1);
                break;
            }
        }
        return ops;
    }
};
