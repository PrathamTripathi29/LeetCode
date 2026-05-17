class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k == 1){
            return (r-l+1);
        }
        vector<long long> powers;
        int i=0;
        while(1){
            long long val = 1;
            for(int j=0; j<k; j++){
                val *= i;
                if(val > (long long)INT_MAX) break;
            }
            if(val > (long long)INT_MAX) break;
            powers.push_back(val);
            i++;
        }
        int x = lower_bound(powers.begin(), powers.end(), l) - powers.begin();
        int y = upper_bound(powers.begin(), powers.end(), r) - powers.begin()-1;
        return y-x+1;
    }
};
