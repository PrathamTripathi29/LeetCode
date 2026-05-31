class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(int ast : asteroids){
            if(ast <= m){
                m += ast;
            } else {
                return false;
            }
        }
        return true;
    }
};
