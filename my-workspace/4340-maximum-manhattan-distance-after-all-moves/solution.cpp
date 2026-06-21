class Solution {
public:
    int maxDistance(string moves) {
        int u, d, l, r;
        u = d = r = l = 0;
        int blank = 0;
        for(char ch : moves){
            if(ch == 'U') u++;
            else if(ch == 'D') d++;
            else if(ch == 'L') l++;
            else if(ch == 'R') r++;
            else blank++;
        }
        int mx = max({u, d, l, r});
        if(mx == u){
            u += blank;
        } else if(mx == d){
            d += blank;
        } else if(mx == l){
            l += blank;
        } else if(mx == r){
            r += blank;
        }
        int x = abs(l-r);
        int y = abs(u-d);
        int dist = x+y;
        return dist;
    }
};
