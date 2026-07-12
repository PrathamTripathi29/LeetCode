class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string hS = startTime.substr(0, 2);
        string mS = startTime.substr(3, 5);
        string sS = startTime.substr(6, 8);
        string hE = endTime.substr(0, 2);
        string mE = endTime.substr(3, 5);
        string sE = endTime.substr(6, 8);
        int hDiff = stoi(hE) - stoi(hS);
        int mDiff = stoi(mE) - stoi(mS);
        int sDiff = stoi(sE) - stoi(sS);
        int ans = hDiff*3600 + mDiff*60 + sDiff;
        return ans;
    }
};
