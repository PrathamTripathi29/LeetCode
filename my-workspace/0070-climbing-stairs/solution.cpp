class Solution {
public:
    unordered_map<int,int> mp;
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        if(mp.find(n) == mp.end()){
            mp[n] = climbStairs(n-1) + climbStairs(n-2);
        }
        return mp[n];
    }
};
