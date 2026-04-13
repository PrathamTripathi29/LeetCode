class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int x = 0;
        int y = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(ch == 'N') y++;
            else if(ch == 'S') y--;
            else if(ch == 'E') x++;
            else if(ch == 'W') x--;

            int dist = abs(x) + abs(y);
            ans = max(ans, min(i+1, dist + 2*k));
        }
        return ans;
    }
};
