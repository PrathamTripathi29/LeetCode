class Solution {
public:
    int score(vector<string>& cards, char x) {
        int ans = 0;
        int f = 0;
        int tf = 0;
        int s = 0;
        int ts = 0;
        int xx = 0;
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);

        for(int i=0; i<cards.size(); i++){
            char c1 = cards[i][0];
            char c2 = cards[i][1];
            if(c1 == x && c2 == x) xx++;
            else if(c1 == x){
                f = max(f, ++arr1[c2 - 'a']);
                tf++;
            } else if(c2 == x){
                s = max(s, ++arr2[c1 - 'a']);
                ts++;
            }
        }

        if(f > tf/2){
            ans += tf - f;
            tf = f - (tf -f);
        } else {
            ans += tf/2;
            tf = tf % 2;
        }

        if(s > ts/2){
            ans += ts - s;
            ts = s - (ts - s);
        } else{
            ans += ts/2;
            ts = ts % 2;
        }

        int used = min(tf + ts, xx);
        xx -= min(tf + ts, xx);
        ans = min(ans * 2, ans + xx/2);
        ans += used;

        return ans;
    }
};
