class Solution {
public:
    bool rotateString(string s, string goal) {
        int n1 = s.length();
        int n2 = goal.length();
        if(n1 != n2) return false;
        
        int fa[101][26] = {0};
        fa[0][s[0]-'a'] = 1;

        int state = 0;
        for(int i=1; i<n1; i++){
            for(int j=0; j<26; j++){
                fa[i][j] = fa[state][j];
            }
            int ch = s[i] - 'a';
            fa[i][ch] = i+1;
            state = fa[state][ch];
        }

        state = 0;
        for(int i=0; i<2*n1; i++){
            state = fa[state][goal[i%n1] - 'a'];
            if(state == n1) return true;
        }
        return false;
    }
};
