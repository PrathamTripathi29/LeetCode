class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int d1 = abs(start[0] - target[0]);
        int d2 = abs(start[1] - target[1]);
        if((d1&1) == (d2&1)) return true;
        return false;
    }
};
