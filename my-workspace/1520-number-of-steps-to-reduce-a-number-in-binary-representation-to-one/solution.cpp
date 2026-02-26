class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0;
        int c = 0;
        for(int i = n-1; i > 0; i--){
            if((s[i] & 1) + c == 1){
                steps += 2;
                c = 1;
            } else {
                steps++;
            }
        }
        return steps + c;
    }
};
