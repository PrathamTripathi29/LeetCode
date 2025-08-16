class Solution {
public:
    int minSensors(int n, int m, int k) {
        int sensorsrow = ceil((float)n/(1 + k*2));
        int sensorscol = ceil((float)m/(1 + k*2));
        return sensorsrow * sensorscol;
    }
};
