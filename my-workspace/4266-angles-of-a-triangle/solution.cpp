class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> angles(3);
        if(sides[0] + sides[1] <= sides[2] || sides[1] + sides[2] <= sides[0] || sides[0] + sides[2] <= sides[1]) return {};
        for(int i=0; i<3; i++){
            double cosangle = (double)(sides[i]*sides[i] + sides[(i+1)%3]*sides[(i+1)%3] - sides[(i+2)%3]*sides[(i+2)%3])/(2*sides[i]*sides[(i+1)%3]);
            angles[i] = acos(cosangle);
            angles[i] = angles[i]*(180.0/M_PI);
        }
        sort(angles.begin(), angles.end());
        return angles;
    }
};
