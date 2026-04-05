class Solution {
public:
    bool judgeCircle(string moves) {
        int vert = 0;
        int hori = 0;
        for(char ch : moves){
            if(ch == 'R') hori++;
            else if(ch == 'L') hori--;
            else if(ch == 'U') vert++;
            else if(ch == 'D') vert--;
        }
        if(hori == 0 && vert == 0) return true;
        return false;
    }
};
