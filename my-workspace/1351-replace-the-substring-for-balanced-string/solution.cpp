class Solution {
    /*
        n = 40
        q = 10, w = 10, e = 10, r = 10

        q = 13, w = 9,  e = 8, r = 10

        q(-3), w(+1), e(+2), r(+0)

    */
public:
    int balancedString(string s) {
        int n = s.length();
        int f = n/4;
        int qf, wf, ef, rf;
        qf = wf = ef = rf = 0;
        for(char ch : s){
            if(ch == 'Q') qf++;
            else if(ch == 'W') wf++;
            else if(ch == 'E') ef++;
            else rf++;
        }
        int dq = max(qf-f, 0);
        int dw = max(wf-f, 0);
        int de = max(ef-f, 0);
        int dr = max(rf-f, 0);
        int cq, cw, ce, cr;
        cq = cw = ce = cr = 0;
        int l=0;
        int minLen = n;
        for(int i=0; i<n; i++){
            if(s[i] == 'Q') cq++;
            else if(s[i] == 'W') cw++;
            else if(s[i] == 'E') ce++;
            else cr++;
            while(cq >= dq && cw >= dw && ce >= de && cr >= dr){
                minLen = min(minLen, i-l+1);
                if(s[l] == 'Q') cq--;
                else if(s[l] == 'W') cw--;
                else if(s[l] == 'E') ce--;
                else cr--;

                l++;
            }
        }
        return minLen;
    }
};
