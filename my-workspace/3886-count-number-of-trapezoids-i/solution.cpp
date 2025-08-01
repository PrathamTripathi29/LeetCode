class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int mod = 1e9 + 7;
        unordered_map<int, long long> freq;
        for(int i=0; i<n; i++){
            if(freq.find(points[i][1]) != freq.end()){
                freq[points[i][1]]++;
            } else {
                freq[points[i][1]] = 1;
            }
        }
        long long ans = 0;
        long long trapez = 0;
        for(auto &pair : freq){
            long long lines = pair.second * (pair.second - 1)/2;
            ans = (ans + trapez * lines) % mod;
            trapez = (trapez + lines) % mod;
        }
        return (int)ans;
    }
};
