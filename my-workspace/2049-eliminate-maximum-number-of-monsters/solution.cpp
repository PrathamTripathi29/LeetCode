class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<float> time;
        for(int i = 0; i<n; i++){
            float t = (float)dist[i]/speed[i];
            time.push_back(t);
        }
        int k = 0;
        sort(time.begin(), time.end());
        for(int i=0; i<n-1; i++){
            if(time[i] > 0){
                time[i+1] = time[i+1] - ++k;
            }
            else{
                return i;
            }
        }
        if(time[n-1] > 0){
            return n;
        }
        return n-1;
    }
};
